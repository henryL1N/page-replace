//
// Created by 林庆华 on 2018/4/16.
//

#include "FIFO.h"

Block *FIFO::replace(list<Block *> *blocks) {
    Block *block = nullptr;
    for (auto it:*blocks) {
        if (it->getPageNumber() == this->loadQueue.front()) {
            block = it;
            block->load(this->loadQueue.back());
            this->loadQueue.pop_front();
            break;
        }
    }
    return block;
}

void FIFO::monitor(Request *request) {
    for (auto it:this->loadQueue) {
        if (it == request->getPageNumber()) {
            return;
        }
    }
    this->loadQueue.push_back(request->getPageNumber());
}
