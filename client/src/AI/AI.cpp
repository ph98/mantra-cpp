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
    // fill_map_weights(world);
}   

void AI::pick(World *world) {
    world->pickHero(constants1.pick_arr[constants1.pick_phase]);
    constants1.pick_phase++ ;
}
void AI::move(World *world) {
    print_map(world);
    for(auto hero : world->getMyHeroes() ){
        int heroRow = hero->getCurrentCell().getRow() ;
        int heroCol = hero->getCurrentCell().getColumn() ; 
        if(my_map[heroRow][heroCol].dist_to_objective >= 2 ){
            world->moveHero(hero->getId() ,my_map[heroRow][heroCol].PATH[0] ) ;
        }
    }
}


void AI::action(World *world) {
    // print_map(world);

}