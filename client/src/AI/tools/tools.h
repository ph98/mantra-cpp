//
// Created by parham on 2/9/19.
//

#ifndef AIC19_CLIENT_CPP_TOOLS_H
#define AIC19_CLIENT_CPP_TOOLS_H
#include <Model/Interface/World.h>
#include <bits/stdc++.h>
using namespace std;
enum colors {
    black=30 ,
    red=31,
    green=32,
    yellow=33,
    blue=34,
    magenta=35,
    cyan=36,
    white=37
};

void print_map(World *world);
void print( colors c , char ch , bool bg = false );

#endif //AIC19_CLIENT_CPP_TOOLS_H
