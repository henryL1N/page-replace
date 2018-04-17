//
// Created by 林庆华 on 2018/4/16.
//

#include "Optimal.h"

Optimal::Optimal(list<Request> *requestList) {
    this->requestList=requestList;
    this->it=this->requestList->begin();

}

Block *Optimal::replace(list<Block> *blocks) {
    return nullptr;
}

void Optimal::monitor(Request *request) {
    if(this->it->getPageNumber()==request->getPageNumber()) {
        it++;
    }
}
