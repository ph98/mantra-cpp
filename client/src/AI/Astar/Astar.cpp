//
// Created by ywcn on 2/9/19.
//
#include "Astar.h"
int Astar::Huirstic(Cell cell , int row , int col)
{
    return ( abs( row-cell.getRow() )+abs( col- cell.getColumn() ) );
}

vector<Cell> Astar::calcPath(World *world , Cell start , Cell goal){


    vector<Cell> closedSet ;
    vector<Cell> openSet ;
    openSet.push_back(start) ;


    map<Cell , Cell> cameFrom  ;


    int  gScore[max_of_size][max_of_size]  ;

    for (int i = 0; i < max_of_size; ++i) {
        for (int j = 0; j < max_of_size; ++j) {
            gScore[i][j] = INT_MAX ;
        }
    }
    gScore[start.getRow()][start.getColumn()] = 0 ;

    int  fScore[max_of_size][max_of_size]  ;

    for (int i = 0; i < max_of_size; ++i) {
        for (int j = 0; j < max_of_size; ++j) {
            fScore[i][j] = INT_MAX ;
        }
    }
    fScore[start.getRow()][start.getColumn()] = Huirstic(start , goal.getRow() , start.getColumn() ) ;

    while(openSet.size() > 0  ){

        // get the min

        int temp = INT_MAX;
        vector<Cell>::iterator itCell ;
        for ( vector<Cell>::iterator it = openSet.begin();
        it !=openSet.end() ;
        next(it)) {
            Cell c = *it ;
            if(fScore[c.getRow()][c.getColumn()] <temp ){
                temp = fScore[c.getRow()][c.getColumn()] ;
                itCell = it ;
            }
        }

        //        return if found
        Cell current = *itCell ;
        if(current.isInObjectiveZone()){
            found_path.push_back(current) ;
            return found_path;
        }


        openSet.erase(itCell) ;
        closedSet.push_back(current);

        int move_x[] = {0 , 0 , -1 , +1 };
        int move_y[] = {-1 , +1 , 0 , 0 };

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                //we have each neghbor
                if(isinVector(closedSet , current.getRow()+move_x[i] , current.getColumn()+move_y[j]))
                    continue ;  // Ignore the neighbor which is already evaluated.

                int tentative_gScore =gScore[current.getRow()][current.getColumn()] + is_rock(world , current.getRow()+move_x[i] , current.getColumn()+move_y[j]) ;

                Cell neighbor = world->getMap().getCell(current.getRow()+move_x[i] , current.getColumn()+move_y[j]) ;
                // Discover new cell :

                if( ! isinVector(openSet , current.getRow()+move_x[i] , current.getColumn()+move_y[j]))
                    openSet.push_back(neighbor);
                else if(tentative_gScore >= gScore[current.getRow()+move_x[i]][ current.getColumn()+move_y[j]])
                    continue ;

                cameFrom[neighbor] = current ;
                gScore[current.getRow()+move_x[i]][ current.getColumn()+move_y[j]] = tentative_gScore ;
                fScore[current.getRow()+move_x[i]][current.getColumn()+move_y[j]] = gScore[current.getRow()+move_x[i]][current.getColumn()+move_y[j]] + Huirstic(neighbor , goal.getRow() , goal.getColumn()) ;

            }
        }



    }
}

bool Astar::isinVector(vector<Cell> list ,int row , int col ){
    for(auto cell : list){
        if (cell.getColumn() == col && cell.getRow() == row)
            return true ;
    }
    return false;
}