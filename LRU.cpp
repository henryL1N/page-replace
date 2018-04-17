//
// Created by 林庆华 on 2018/4/17.
//

#include "LRU.h"

void LRU::monitor(Request *request) {
    for (auto it = this->accessQueue.begin(); it != this->accessQueue.end(); it++) {
        if (*it == request->getPageNumber()) {
            int n = *it;
            this->accessQueue.erase(it);
            this->accessQueue.push_back(n);
            return;
        }
    }
    this->accessQueue.push_back(request->getPageNumber());
}

Block *LRU::replace(list<Block *> *blocks) {
    Block *block = nullptr;
    for (auto it:*blocks) {
        if (it->getPageNumber() == this->accessQueue.front()) {
            block = it;
            block->load(this->accessQueue.back());
            this->accessQueue.pop_front();
            break;
        }
    }
    return block;
}
