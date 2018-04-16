//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_OPTIMAL_H
#define MAIN_CPP_OPTIMAL_H


#include "PageReplacementAlgorithm.h"

class Optimal : public PageReplacementAlgorithm{
public:
    Block *replace(list<Block> *blocks) override;

};


#endif //MAIN_CPP_OPTIMAL_H
