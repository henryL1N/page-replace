//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_PAGEREPLACEMENTALGORITHMTESTER_H
#define MAIN_CPP_PAGEREPLACEMENTALGORITHMTESTER_H


#include "Memory.h"

class PageReplacementAlgorithmTester {
private:
    Memory *memory;
    list<Request> *requestList;
    PageReplacementAlgorithm *optimal;
    PageReplacementAlgorithm *fifo;
    PageReplacementAlgorithm *lru;


public:
    PageReplacementAlgorithmTester();

    void run();

    void run(PageReplacementAlgorithm *pageReplacementAlgorithm);

};


#endif //MAIN_CPP_PAGEREPLACEMENTALGORITHMTESTER_H
