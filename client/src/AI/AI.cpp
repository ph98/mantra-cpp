//        888b     d888        d8888 888b    888 88888888888 8888888b.         d8888
//        8888b   d8888       d88888 8888b   888     888     888   Y88b       d88888
//        88888b.d88888      d88P888 88888b  888     888     888    888      d88P888
//        888Y88888P888     d88P 888 888Y88b 888     888     888   d88P     d88P 888
//        888 Y888P 888    d88P  888 888 Y88b888     888     8888888P"     d88P  888
//        888  Y8P  888   d88P   888 888  Y88888     888     888 T88b     d88P   888
//        888   "   888  d8888888888 888   Y8888     888     888  T88b   d8888888888
//        888       888 d88P     888 888    Y888     888     888   T88b d88P     888

#include "AI.h"
#include <bits/stdc++.h>
#include "AI/tools/tools.h"
#include "AI/Astar/Astar.h"

using namespace std;

void AI::preProcess(World *world) {
//    world->getMap().getObjectiveZone()[0].
    print_map(world);

}

void AI::pick(World *world) {
    world->pickHero(HeroName(rand()%4));
}

void AI::move(World *world) {
//    for(auto hero : world->getMyHeroes() ){
//        auto  temp = Direction(rand()%4);
//        world->moveHero(hero->getId() ,  temp );
//        cout<< "name: "<< hero->getId() << " -> "<< temp << endl ;
//    }
}

void AI::action(World *world) {
//    print_map(world);
//    world->castAbility(1,world->getHero(1).getAbilities()[0], world->getHero(1).getCurrentCell().getColumn() + 2 ,world->getHero(1).getCurrentCell().getRow() + 2   );
//    cout<< world->getAP() << endl ;
//    for(auto ab : world->getMyCastAbilities() ){
//        cout<< "abilitys : " <<  ab->getAbilityName() <<endl ;
//    }
    Astar myAstar ;
    vector<Cell> ans ;
    ans = myAstar.calcPath(world , world->getMyHeroes()[0]->getCurrentCell() , world->getMap().getObjectiveZone()[0]);
    cout<<"================== A* path : " <<endl ;
    for(auto each : ans)
        cout<<each.getRow() << "," << each.getColumn() <<endl ;

}
