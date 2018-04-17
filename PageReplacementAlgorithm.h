//
// Created by 林庆华 on 2018/4/13.
//

#ifndef MAIN_CPP_PAGEREPLACEMENTALGORITHM_H
#define MAIN_CPP_PAGEREPLACEMENTALGORITHM_H

#include <list>
#include "Block.h"
#include "Request.h"

using namespace std;

class PageReplacementAlgorithm {

public:

    virtual void monitor(Request *request)=0;

    virtual Block *replace(list<Block *> *blocks)=0;

};

#endif //MAIN_CPP_PAGEREPLACEMENTALGORITHM_H
