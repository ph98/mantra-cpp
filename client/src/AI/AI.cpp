//        888b     d888        d8888 888b    888 88888888888 8888888b.         d8888
//        8888b   d8888       d88888 8888b   888     888     888   Y88b       d88888
//        88888b.d88888      d88P888 88888b  888     888     888    888      d88P888
//        888Y88888P888     d88P 888 888Y88b 888     888     888   d88P     d88P 888
//        888 Y888P 888    d88P  888 888 Y88b888     888     8888888P"     d88P  888
//        888  Y8P  888   d88P   888 888  Y88888     888     888 T88b     d88P   888
//        888   "   888  d8888888888 888   Y8888     888     888  T88b   d8888888888
//        888       888 d88P     888 888    Y888     888     888   T88b d88P     888

#include "AI.h"
#include <iostream>
using namespace std;
enum colors {red=30 , blue , white};
void print(World *world);
void print_map(World *world);



void AI::preProcess(World *world) {


    world->pickHero(SENTRY);
    world->pickHero(BLASTER);
    world->pickHero(BLASTER);



}

void AI::pick(World *world) {




}

void AI::move(World *world) {
    
}

void AI::action(World *world) {
    print_map(world);
}

void print_map(World *world){
    world->getHeroConstants()[0]->getName();
    for(auto rows : world->getMap().getCells()){
        for(auto cell : rows )
        {
            if(cell->isWall())
                cout << '#';
            else if(cell->isInMyRespawnZone())
                cout << "?";
            else if(cell->isInObjectiveZone())
                cout << "@";
            else if(cell->isInOppRespawnZone())
                cout<<"!";
            else if(cell->isInVision())
                cout << "V";
            else
                cout<<' ';
        }
        cout<<endl ;
    }
}

void print(){
    cout << "\033[1;31mb\033[0m";

}