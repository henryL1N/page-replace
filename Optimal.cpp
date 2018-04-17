//
// Created by 林庆华 on 2018/4/16.
//

#include "Optimal.h"

Optimal::Optimal(list<Request *> *requestList) {
    this->requestList = requestList;
}

Block *Optimal::replace(list<Block *> *blocks) {
    list<Block *> tempBlocks = *blocks;
    Block *block = nullptr;
    bool hasEmptyBlock = false;
    for (auto itReq:*this->requestList) {

        for (auto itBlk = tempBlocks.begin(); itBlk != tempBlocks.end(); itBlk++) {
            if ((*itBlk)->isEmpty()) {
                block = *itBlk;
                hasEmptyBlock = true;
                break;
            } else if ((*itBlk)->getPageNumber() == itReq->getPageNumber()) {
                block = (*itBlk);
                tempBlocks.erase(itBlk);
                break;
            }
        }
        if (hasEmptyBlock) {
            block->load((*(this->requestList->begin()))->getPageNumber());
        }
    }
    if (!block) {
        block=tempBlocks.front();
    }
    return block;
}

void Optimal::monitor(Request *request) {
    while (request != *this->requestList->begin()) {
        this->requestList->pop_front();
    }
}
