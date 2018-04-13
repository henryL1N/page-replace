//
// Created by 林庆华 on 2018/4/13.
//

#ifndef MAIN_CPP_PAGEREPLACEMENTALGORITHM_H
#define MAIN_CPP_PAGEREPLACEMENTALGORITHM_H

#include <list>
#include "Block.h"
using namespace std;

class PageReplacementAlgorithm {

public:

    virtual void replace(list<Block> blocks, int pageNumber);

};

#endif //MAIN_CPP_PAGEREPLACEMENTALGORITHM_H
