//
// Created by parham on 2/9/19.
//
#include "tools.h"

void print_map(World *world){
    for(auto rows : world->getMap().getCells()){
        for(auto cell : rows )
        {
            if (!( world->getMyHero(cell->getRow() , cell->getColumn() ) == Hero::NULL_HERO) ){
                cout<<'H' ;
            }
            else if(cell->isWall())
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

void print(World *world){
    cout << "\033[1;31mb\033[0m";

}