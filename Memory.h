//
// Created by 林庆华 on 2018/4/13.
//

#ifndef MAIN_CPP_MEMORY_H
#define MAIN_CPP_MEMORY_H

#include <list>
#include "Block.h"
#include "Request.h"
#include "PageReplacementAlgorithm.h"

using namespace std;

class Memory {

public:

    enum RequestResultEnum {

        SUCCESS,//successfully requested in recently stored pages

        LOADED,//requested page was not stored in the blocks and one or more blocks are empty

        REPLACED//requested page was not stored in the blocks and none of them is empty

    };

private:

    list<Block> *blocks;
    RequestResultEnum requestResult;
    PageReplacementAlgorithm *pageReplacementAlgorithm;

public:
    RequestResultEnum getRequestResult() const;

    void setPageReplacementAlgorithm(PageReplacementAlgorithm *pageReplacementAlgorithm);

    explicit Memory(long blocksCount);

    Block *response(Request *request);

};


#endif //MAIN_CPP_MEMORY_H
