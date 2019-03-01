//
// Created by parham on *******.
//

#ifndef AIC19_CLIENT_CPP_FILL_THE_MAP_H
#define AIC19_CLIENT_CPP_FILL_THE_MAP_H
#include <Model/Interface/World.h>
#include <bits/stdc++.h>
#include "AI/constants/constants.h"


using namespace std;

struct mycell {
    int dist_to_objective = 0;
    vector<Direction> PATH ;
    map<AbilityName , int > weight ;
};

void fill_dist_to_objective(World *world  , mycell my_map[][MAX_HEIGHT]);

void fill_map_weights(World *world  , mycell my_map[][MAX_HEIGHT]);

#endif //AIC19_CLIENT_CPP_FILL_THE_MAP_H