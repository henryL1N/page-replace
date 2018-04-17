//
// Created by 林庆华 on 2018/4/16.
//

#include "Optimal.h"

Optimal::Optimal(list<Request *> *requestList) {
    this->requestList = new list<Request *>();
    for (auto it:*requestList) {
        this->requestList->push_back(it);
    }
}

Block *Optimal::replace(list<Block *> *blocks) {
    list<Block *> tempBlocks = *blocks;
    Block *block = nullptr;
    bool recentRequest=true;
    for (auto itReq:*this->requestList) {
        if (recentRequest) {
            recentRequest=false;
            continue;
        }
        for (auto itBlk = tempBlocks.begin(); itBlk != tempBlocks.end(); itBlk++) {
            if ((*itBlk)->isEmpty()) {
                block = *itBlk;
                break;
            } else if ((*itBlk)->getPageNumber() == itReq->getPageNumber()) {
                tempBlocks.erase(itBlk);
                if (tempBlocks.size() == 1) {
                    block = tempBlocks.front();
                }
                break;
            }
        }
        if (block) {
            break;
        }
    }
    if (!block) {
        block = tempBlocks.front();
    }
    block->load(this->requestList->front()->getPageNumber());
    return block;
}

void Optimal::monitor(Request *request) {
    while (request != *this->requestList->begin()) {
        this->requestList->pop_front();
    }
}
