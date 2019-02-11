//
// Created by ywcn on 2/9/19.
//

#ifndef AIC19_CLIENT_CPP_ASTAR_H
#define AIC19_CLIENT_CPP_ASTAR_H
#include <Model/Interface/World.h>
#include <bits/stdc++.h>

using namespace std;


class Astar
{
private:
    const int max_of_size = 300 ;
public:

    int Huirstic(Cell cell , int row , int col);
//    Astar (World *world);
    vector<Cell> calcPath(World *world , Cell start , Cell goal);
    vector<Cell> found_path ;
    bool isinVector(vector<Cell> list ,int row , int col );
    int is_rock(World *world , int row , int col ){
        return world->getMap().getCell(row,col ).isWall() ? INT_MAX-10000 : 1 ;
    }
};
#endif //AIC19_CLIENT_CPP_ASTAR_H
