//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_TESTER_H
#define MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_TESTER_H


#include "Memory.h"

/**
 * Page replacement algorithm tester
 * 页面置换算法测试机
 */
class PageReplacementAlgorithmTester {

private:

    /**
     * Memory to respond page requests.
     * 用于响应页面请求的内存。
     */
    Memory *memory;

    /**
     * Page request list.
     * 页面请求列表。
     */
    list<Request *> *requestList;

    /**
     * Run test with specify page replacement algorithm.
     * 以制定的页面置换算法运行测试。
     * @param pageReplacementAlgorithm page replacement algorithm 页面置换算法
     */
    void run(PageReplacementAlgorithm *pageReplacementAlgorithm);

    /**
     * Print test result.
     * 打印测试结果。
     * @param result test result(list of memory snapshot) 测试结果（内存快照的列表）
     */
    void print(list<Memory *> *result);

    /**
     * Print page request list.
     * 打印页面请求列表。
     */
    void printRequest();

    /**
     * Print horizontal line according to test result.
     * 按照测试结果打印横线。
     * @param result test result(list of memory snapshot) 测试结果（内存快照的列表）
     */
    void printLine(list<Memory *> *result);

    /**
     * Print page number of block according to test result and block position.
     * 按照测试结果及块位置打印块的页面编号。
     * @param result test result(list of memory snapshot) 测试结果（内存快照的列表）
     * @param index block position in blocks list 块在块列表中的位置
     */
    void printPageNumber(list<Memory *> *result, unsigned long index);

    /**
     * Print request result according to test result.
     * 按照测试结果打印请求结果。
     * @param result test result(list of memory snapshot) 测试结果（内存快照的列表）
     */
    void printRequestResult(list<Memory *> *result);

public:

    /**
     * Initialization of test.
     * 初始化测试。
     */
    PageReplacementAlgorithmTester();

    /**
     * Run test.
     * 运行测试。
     */
    void run();

};


#endif //MAIN_CPP_PAGE_REPLACEMENT_ALGORITHM_TESTER_H
