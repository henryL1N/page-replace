//
// Created by 林庆华 on 2018/4/16.
//

#include "FIFO.h"

void FIFO::monitor(Request *request) {
    //iterate the queue to determine if the requested page number already exists in the queue
    //迭代队列以判断队列中是否已存在请求的页面编号
    for (auto it:this->loadQueue) {
        //if page number exists, return(unnecessary to push to the queue)
        //若页面编号已存在，返回（无需送入队列）
        if (it == request->getPageNumber()) {
            return;
        }
    }
    //if page number not exists, push to the end of queue
    //若页面编号不存在，送入队列末端
    this->loadQueue.push_back(request->getPageNumber());
}

Block *FIFO::replace(list<Block *> *blocks) {
    //declare block to be replaced and returned
    //声明用于置换及返回的块
    Block *block = nullptr;
    //iterate block list to locate the block contains page that was loaded earliest
    //迭代块列表以找到最早加载的块
    for (auto it:*blocks) {
        //if block contains the same page of the front of queue, replace it and remove the front of queue
        //若块储存的页面编号与队列前端相等，置换该块并移除队列前端的页面编号
        if (it->getPageNumber() == this->loadQueue.front()) {
            block = it;
            block->load(this->loadQueue.back());
            this->loadQueue.pop_front();
            break;
        }
    }
    //return replaced block
    //返回置换后的块
    return block;
}
