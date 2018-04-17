//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_TESTER_H
#define MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_TESTER_H


#include "Memory.h"

class PageReplacementAlgorithmTester {

private:

    Memory *memory;

    list<Request *> *requestList;

    void run(PageReplacementAlgorithm *pageReplacementAlgorithm);

    void print(list<Memory *> *result);

    void printRequest();

    void printLine(list<Memory *> *result);

    void printPageNumber(list<Memory *> *result, unsigned long index);

    void printRequestResult(list<Memory *> *result);

public:

    PageReplacementAlgorithmTester();

    void run();

};


#endif //MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_TESTER_H
