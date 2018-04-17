//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_OPTIMAL_H
#define MAIN_CPP_OPTIMAL_H


#include "PageReplacementAlgorithm.h"

class Optimal : public PageReplacementAlgorithm {
private:
    list<Request *> *requestList;
public:
    explicit Optimal(list<Request *> *requestList);

    Block *replace(list<Block *> *blocks) override;

    void monitor(Request *request) override;
};


#endif //MAIN_CPP_OPTIMAL_H
