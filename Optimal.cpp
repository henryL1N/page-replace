//
// Created by 林庆华 on 2018/4/16.
//

#include "Optimal.h"

Optimal::Optimal(list<Request *> *requestList) {
    for (auto it:*requestList) {
        this->requestList.push_back(it);
    }
}

Block *Optimal::replace(list<Block *> *blocks) {
    //copy block list passed by memory
    //复制内存传入的块列表
    list<Block *> tempBlocks = *blocks;
    //declare block to be return
    //声明用于返回的块
    Block *block = nullptr;
    //boolean to bypass recent request in loop
    //用于在循环中跳过当前请求的标志位
    bool recentRequest = true;
    //iterate request list
    //迭代请求列表
    for (auto itReq:this->requestList) {
        //bypass recent request
        //跳过当前请求
        if (recentRequest) {
            recentRequest = false;
            continue;
        }
        //iterate block list to exclude block that will be request in the future
        //迭代块列表以排除即将再次请求的块
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
    block->load(this->requestList.front()->getPageNumber());
    return block;
}

void Optimal::monitor(Request *request) {
    //remove requests before recent request in the list
    //在请求列表中移除当前请求之前的请求
    while (request != *this->requestList.begin()) {
        this->requestList.pop_front();
    }
}
