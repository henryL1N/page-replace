//
// Created by 林庆华 on 2018/4/16.
//

#include "Optimal.h"

Optimal::Optimal(list<Request *> *requestList) {
    this->requestList = requestList;
}

Block *Optimal::replace(list<Block *> *blocks) {
    list<Block *> tempBlocks;
    for (auto &it:*this->requestList) {

    }


    return nullptr;
}

void Optimal::monitor(Request *request) {
    while (request != *this->requestList->begin()) {
        this->requestList->pop_front();
    }
}
