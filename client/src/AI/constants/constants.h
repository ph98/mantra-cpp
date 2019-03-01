
//
// Created by parham on *******.
//

#ifndef AIC19_CLIENT_CPP_CONSTANTS_H
#define AIC19_CLIENT_CPP_CONSTANTS_H
#include <Model/Interface/World.h>
#include <bits/stdc++.h>
// #include "AI/fill_the_map/fill_the_map.h"

using namespace std;
const int MAX_WIDTH = 32 ;
const int MAX_HEIGHT = 32 ;


struct constantClass {
    HeroName pick_arr[4] = {BLASTER , BLASTER , BLASTER , BLASTER} ;
    int pick_phase = 0 ; 
    const int max_attack_weight = 500 ;
    int distination_col ;
    int distination_row ;
} ;

#endif //AIC19_CLIENT_CPP_CONSTANTS_H