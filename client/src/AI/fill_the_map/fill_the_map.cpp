#include "fill_the_map.h"

// define variables : 

constantClass constants; 

// static mycell my_map[MAX_WIDTH][MAX_HEIGHT];


void fill_dist_to_objective(World *world  , mycell my_map[][MAX_HEIGHT] )
{
  for(auto row : world->getMap().getCells()){
        for(auto cell : row){
            int row = world->getMap().getObjectiveZone()[world->getMap().getObjectiveZone().size()/2]->getRow();
            int col = world->getMap().getObjectiveZone()[world->getMap().getObjectiveZone().size()/2]->getColumn();
            vector<Direction> dir =  world->getPathMoveDirections(cell->getRow() , cell->getColumn() , row,col );
            int dist = dir.size();
            my_map[cell->getRow() ][cell->getColumn()].PATH = dir ;
            my_map[cell->getRow() ][cell->getColumn()].dist_to_objective = dist;
        }
  }
}


void fill_map_weights(World *world   , mycell my_map[][MAX_HEIGHT]){

    int ans = 0 ; 
      // make all zero each turn :
    cout<< world->getMap().getColumnNum() <<endl ;
    for(int i = 0; i < world->getMap().getColumnNum(); i++)
        for(int j = 0; j < world->getMap().getRowNum() ; j++)
            for(auto ability : world->getAbilityConstants())
                my_map[i][j].weight[ability->getName()] = 0;

    // fill the weights : 
    for(int i = 0; i < world->getMap().getColumnNum(); i++)
        for(int j = 0; j < world->getMap().getRowNum() ; j++){
            for(auto ability : world->getAbilityConstants() ){
                int Range = ability->getRange() ;
                for(int i1 = -Range; i1 <= +Range; i1++)
                    for(int j1 = -Range; j1 <= +Range; j1++)
                    {
                        if( world->getMap().isInMap(i + i1 , j+j1) && world->manhattanDistance(i , j , i1 , j1 ) <= Range )
                            if( world->getOppHero(i + i1 , j + j1 ).getCurrentHP() > 0 ){
                                my_map[i][j].weight[ability->getName() ] += ( constants.max_attack_weight - world->getOppHero(i + i1 , j + j1 ).getCurrentHP()  );
                                 cout<< "--> " << my_map[i][j].weight[ability->getName() ] <<endl ;
                            }
                            //  cout<< "--> " << world->getOppHero(i + i1 , j + j1 ).getCurrentHP()<<endl ;
                    }
            }
        }


    cout<<ans<<endl ; 

}