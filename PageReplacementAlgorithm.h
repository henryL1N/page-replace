//
// Created by 林庆华 on 2018/4/13.
//

#ifndef MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_H
#define MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_H

#include <list>
#include "Block.h"
#include "Request.h"

using namespace std;

/**
 * Abstract page replacement algorithm
 * 抽象页面置换算法
 */
class PageReplacementAlgorithm {

public:

    /**
     * Monitor every page request to prepare for replacement.
     * Ensure to call this method prior to other operations once receive a page request.
     * 监视每个页面请求，作为页面置换的依据。
     * 必须保证每次收到请求时首先调用本方法。
     * @param request page request 页面请求
     */
    virtual void monitor(Request *request)=0;

    /**
     * Core method to select the block to replace page.
     * 选择块并置换页面的核心方法。
     * @param blocks list of the blocks in the memory 内存中的块列表
     * @return selected and page replaced block 经选择并已置换页面的块
     */
    virtual Block *replace(list<Block *> *blocks)=0;

};

#endif //MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_H
