//    8888b   d8888       d88888 8888b   888     888     888   Y88b       d88888
//    88888b.d88888      d88P888 88888b  888     888     888    888      d88P888
//    888Y88888P888     d88P 888 888Y88b 888     888     888   d88P     d88P 888
//    888 Y888P 888    d88P  888 888 Y88b888     888     8888888P"     d88P  888
//    888  Y8P  888   d88P   888 888  Y88888     888     888 T88b     d88P   888
//    888   "   888  d8888888888 888   Y8888     888     888  T88b   d8888888888
//    888       888 d88P     888 888    Y888     888     888   T88b d88P     888

#include <bits/stdc++.h>
#include "AI.h"
#include "AI/tools/tools.h"
#include "AI/fill_the_map/fill_the_map.h"
#include "AI/constants/constants.h"

using namespace std;

mycell my_map[MAX_WIDTH][MAX_HEIGHT];
constantClass constants1 ; 

void AI::preProcess(World *world) {
    // cout<< "Turn -> " << world->getCurrentTurn()<<endl ; 
    fill_dist_to_objective(world , my_map) ;
}   

void AI::pick(World *world) {
    world->pickHero(constants1.pick_arr[constants1.pick_phase]);
    constants1.pick_phase++ ;
}
void AI::move(World *world) {
    // print_map(world);
    
    for(auto hero : world->getMyHeroes() ){
        if( !hero->getRemRespawnTime() ){

            int heroRow = hero->getCurrentCell().getRow() ;
            int heroCol = hero->getCurrentCell().getColumn() ; 
            if( hero->getCurrentCell().isInObjectiveZone() && hero->getAbility(BLASTER_BOMB).getRemCooldown() )
            {
                auto direct = world->getPathMoveDirections(hero->getCurrentCell().getRow(),
                hero->getCurrentCell().getColumn(),constants1.distination_row,constants1.distination_col) ;
                if( direct.size() >= 2  ){
                    world->moveHero(hero->getId() , direct[0]) ;    
                } 
            }
             else if(my_map[heroRow][heroCol].dist_to_objective >= 2 ){
                world->moveHero(hero->getId() ,my_map[heroRow][heroCol].PATH[0] ) ;
            }
        }
    }
}


void AI::action(World *world) {
    print_map(world);

    fill_map_weights(world ,  my_map);

    // for(int i = 0; i <32; i++)
    // {
    //     for(int j = 0; j <32 ; j++)
    //     {
    //         cout<< my_map[i][j].weight[BLASTER_BOMB] << setw(4) ; 
    //     }
    //     cout<<"\n";
    // }
    int maxScore = 0 ; 
    for(auto cell : world->getMap().getObjectiveZone()){
        if(maxScore <= my_map[cell->getRow()][cell->getColumn()].weight[BLASTER_BOMB] ){
            maxScore = my_map[cell->getRow()][cell->getColumn()].weight[BLASTER_BOMB] ;
            constants1.distination_row = cell->getRow() ;
            constants1.distination_col = cell->getColumn() ;
           }
    }
    //  cout<< constants1.distination_row << " " << constants1.distination_col << " " << 
            // world->getMap().getCell(constants1.distination_row ,constants1.distination_col).isWall() <<endl;
        
    for(auto hero : world->getMyHeroes()){
        int target_col =-1 ; 
        int target_row =-1 ; 
        int max_target = -1 ; 
        // cout<< hero->getId() << "==> " <<  hero->getAbility(BLASTER_BOMB).getRemCooldown() <<endl ;
        if(!hero->getRemRespawnTime())
            if(!hero->getAbility(BLASTER_BOMB).getRemCooldown())
            {
                int Range = world->getAbilityConstants()[BLASTER_BOMB]->getRange() ;
                int i = hero->getCurrentCell().getRow() ;
                int j = hero->getCurrentCell().getColumn() ;

                for(int i1 = -Range; i1 <= +Range; i1++)
                    for(int j1 = -Range; j1 <= +Range; j1++)
                    {
                        if( world->getMap().isInMap(i + i1 , j+j1) && world->manhattanDistance(i , j , i1 , j1 ) <= Range )
                            if(max_target <= my_map[i + i1][j+ j1].weight[BLASTER_BOMB] ){
                                max_target = my_map[i + i1][j+ j1].weight[BLASTER_BOMB] ;
                                target_row = i + i1 ;
                                target_col = j + j1 ;
                            }
                    }
                    if(target_col > -1 && my_map[target_row][target_col].weight[BLASTER_ATTACK]>0 )
                        world->castAbility(hero->getId() , BLASTER_BOMB , target_row , target_col);
            }
            else if( !hero->getAbility(BLASTER_ATTACK).getRemCooldown() )
            {
                int Range = world->getAbilityConstants()[BLASTER_ATTACK]->getRange() ;
                int i = hero->getCurrentCell().getRow() ;
                int j = hero->getCurrentCell().getColumn() ;

                for(int i1 = -Range; i1 <= +Range; i1++)
                    for(int j1 = -Range; j1 <= +Range; j1++)
                    {
                        if( world->getMap().isInMap(i + i1 , j+j1) && world->manhattanDistance(i , j , i1 , j1 ) <= Range 
                            && world->isInVision(i,j, i + i1 ,  j+j1 )
                        )
                            if(max_target <= my_map[i + i1][j+ j1].weight[BLASTER_ATTACK] ){
                                max_target = my_map[i + i1][j+ j1].weight[BLASTER_ATTACK] ;
                                target_row = i + i1 ;
                                target_col = j+ j1 ;
                            }
                    }
                    cout<<target_row << " " << target_col <<"  : "<<my_map[target_row][target_col].weight[BLASTER_ATTACK] <<endl ;
                    if( target_col > -1 && my_map[target_row][target_col].weight[BLASTER_ATTACK]>0 && world->isInVision(i , j , target_row , target_col))
                        world->castAbility(hero->getId() , BLASTER_ATTACK , target_row , target_col);
            }
        
    }


}