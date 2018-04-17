//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_OPTIMAL_H
#define MAIN_CPP_OPTIMAL_H

#include "PageReplacementAlgorithm.h"

class Optimal : public PageReplacementAlgorithm {

private:

    /**
     * recent and after request list
     * 当前及之后的请求列表
     */
    list<Request *> requestList;

public:

    /**
     * Construct with complete request list.
     * Because optimal replacement algorithm is not implementable theoretically
     * algorithm which base on requests of the future.
     * 以完整的请求列表构造最佳置换算法对象。
     * 因为最佳置换算法是依赖将来的请求列表的无法实现的理论算法。
     * @param requestList complete request list 完整的请求列表
     */
    explicit Optimal(list<Request *> *requestList);

    void monitor(Request *request) override;

    Block *replace(list<Block *> *blocks) override;

};

#endif //MAIN_CPP_OPTIMAL_H
