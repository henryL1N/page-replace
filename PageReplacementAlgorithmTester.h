//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_PAGEREPLACEMENTALGORITHMTESTER_H
#define MAIN_CPP_PAGEREPLACEMENTALGORITHMTESTER_H


#include "Memory.h"

class PageReplacementAlgorithmTester {
private:
    Memory *memory;
    list<Request *> *requestList;
//    PageReplacementAlgorithm *optimal;
//    PageReplacementAlgorithm *fifo;
//    PageReplacementAlgorithm *lru;


public:
    PageReplacementAlgorithmTester();

    void run();

    void run(PageReplacementAlgorithm *pageReplacementAlgorithm);

    void print(list<Memory *> *result);

    void printLine(list<Memory *> *result);

    void printPageNumber(list<Memory *> *result, unsigned long index);

    void printRequestResult(list<Memory *> *result);

    void printRequest();
};


#endif //MAIN_CPP_PAGEREPLACEMENTALGORITHMTESTER_H
