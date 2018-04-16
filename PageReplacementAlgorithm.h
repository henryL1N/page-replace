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

    virtual void replace(list<Block> *blocks, int pageNumber)=0;

    virtual void replace(list<Block> *blocks, list<Request> *requestList)=0;

};

#endif //MAIN_CPP_PAGEREPLACEMENTALGORITHM_H
