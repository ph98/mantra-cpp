//
// Created by parham on 2/9/19.
//
#include "tools.h"

void print_map(World *world){
    for(auto rows : world->getMap().getCells()){
        for(auto cell : rows )
        {
            if (!( world->getMyHero(cell->getRow() , cell->getColumn() ) == Hero::NULL_HERO) )
                print(red , HeroName_to_string( world->getMyHero(cell->getRow() , cell->getColumn() ).getName())[0] , true );
            else if (!( world->getOppHero(cell->getRow() , cell->getColumn() ) == Hero::NULL_HERO) )
                print(blue , HeroName_to_string( world->getOppHero(cell->getRow() , cell->getColumn() ).getName())[0] , true );
            else if(cell->isWall())
                print(white,  '#');
            else if(cell->isInMyRespawnZone())
                print(magenta, 'R' , true );
            else if(cell->isInObjectiveZone())
                print(yellow ,' ' ,true );
            else if(cell->isInOppRespawnZone())
                print(cyan , '!');
            else if(cell->isInVision())
                print( black , ' ' ,true);
            else
                print(green , ' ');
        }
        cout<<endl ;
    }
}

void print( colors color , char ch , bool bg){
    int temp = (int)color ;
//    cout<< "->" << temp << endl ;
    temp = bg ? temp + 10 : temp ;
    stringstream s ;
    s << temp ;
    string newString = "\033[1;"+ s.str() + "m"+ ch +"\033[0m";
    cout << newString;
}