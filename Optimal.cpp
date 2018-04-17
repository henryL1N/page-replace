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
    //声明用于置换及返回的块
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
        //iterate block list to exclude the blocks contain pages that will be requested again
        //迭代块列表以排除即将再次请求的块
        for (auto itBlk = tempBlocks.begin(); itBlk != tempBlocks.end(); itBlk++) {
            //remove block from list if block contains page that will be requested again
            //若块包含将来请求的页面，则将块从块列表中移除
            if ((*itBlk)->getPageNumber() == itReq->getPageNumber()) {
                tempBlocks.erase(itBlk);
                //if only one block left in list, it is the block to be replaced
                //若列表中仅剩一个块，则置换该块
                if (tempBlocks.size() == 1) {
                    block = tempBlocks.front();
                }
                break;
            }
        }
        //if block was selected, break loop to replace
        //若已找到用于置换的块，则停止迭代请求列表以执行置换
        if (block) {
            break;
        }
    }
    //if none of block was selected (more than one block left in list), first block in list to be replaced
    //若无法找到用于置换的块（列表中仍有多于一个块），则置换列表中首个块
    if (!block) {
        block = tempBlocks.front();
    }
    //replace
    //置换
    block->load(this->requestList.front()->getPageNumber());
    //return replaced block
    //返回置换后的块
    return block;
}

void Optimal::monitor(Request *request) {
    //remove requests before recent request in the list
    //在请求列表中移除当前请求之前的请求
    while (request != *this->requestList.begin()) {
        this->requestList.pop_front();
    }
}
