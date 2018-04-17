//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_FIFO_H
#define MAIN_CPP_FIFO_H

#include "PageReplacementAlgorithm.h"

class FIFO : public PageReplacementAlgorithm {

private:

    list<int> loadQueue;

public:

    void monitor(Request *request) override;

    Block *replace(list<Block *> *blocks) override;

};


#endif //MAIN_CPP_FIFO_H
