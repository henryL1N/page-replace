//
// Created by 林庆华 on 2018/4/17.
//

#ifndef MAIN_CPP_LRU_H
#define MAIN_CPP_LRU_H


#include "PageReplacementAlgorithm.h"

class LRU : public PageReplacementAlgorithm {

private:

    /**
     * queue of accessed page numbers
     * 页面访问队列
     */
    list<int> accessQueue;

public:

    void monitor(Request *request) override;

    Block *replace(list<Block *> *blocks) override;

};


#endif //MAIN_CPP_LRU_H
