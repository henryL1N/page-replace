//
// Created by 林庆华 on 2018/4/17.
//

#include "LRU.h"

void LRU::monitor(Request *request) {
    //iterate the queue to determine if the requested page number already exists in the queue
    //迭代队列以判断队列中是否已存在请求的页面编号
    for (auto it = this->accessQueue.begin(); it != this->accessQueue.end(); it++) {
        //if page number exists, move the page number to the end of queue
        //若页面编号已存在，则将该页面编号移至队列末端
        if (*it == request->getPageNumber()) {
            int n = *it;
            this->accessQueue.erase(it);
            this->accessQueue.push_back(n);
            return;
        }
    }
    //if page number not exists, push to the end of queue
    //若页面编号不存在，送入队列末端
    this->accessQueue.push_back(request->getPageNumber());
}

Block *LRU::replace(list<Block *> *blocks) {
    //declare block to be replaced and returned
    //声明用于置换及返回的块
    Block *block = nullptr;
    //iterate block list to locate the block contains page that are least recently used
    //迭代块列表以找到最久未使用的块
    for (auto it:*blocks) {
        //if block contains the same page of the front of queue, replace it and remove the front of queue
        //若块储存的页面编号与队列前端相等，置换该块并移除队列前端的页面编号
        if (it->getPageNumber() == this->accessQueue.front()) {
            block = it;
            block->load(this->accessQueue.back());
            this->accessQueue.pop_front();
            break;
        }
    }
    //return replaced block
    //返回置换后的块
    return block;
}
