//
// Created by 林庆华 on 2018/4/16.
//

#include "PageReplacementAlgorithmTester.h"
#include "Tools.h"
#include "Optimal.h"
#include "FIFO.h"
#include "LRU.h"

PageReplacementAlgorithmTester::PageReplacementAlgorithmTester() {

    //input blocks count
    //输入内存块数
    unsigned long blocksCount;
    do {
        blocksCount = Tools::userInput<unsigned long>("Please input blocks count 请输入物理块数量(>0): ");
    } while (blocksCount <= 0);

    //initialize memory
    this->memory = new Memory(blocksCount);

    //input request sequence
    char *requestNumberString;
    bool isValidRequest = false;
    list<int> *requestNumberList;
    do {
        requestNumberString = Tools::userInput<char *>(
                "Please input request sequence:\n"
                "请输入页面请求序列\n"
                "(0 <= page number 页面编号 <= 9)\n"
                "(e.g. \"7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1\")\n");
        requestNumberList = Tools::convertStringToIntegerList(requestNumberString, ',');
        if (!requestNumberList->empty()) {
            isValidRequest = true;
            for (int n:*requestNumberList) {
                if (n < 0 || n > 9) {
                    isValidRequest = false;
                }
            }
        }
    } while (!isValidRequest);

    //initialize request list
    this->requestList = new list<Request *>;
    for (auto &it : *requestNumberList) {
        this->requestList->push_back(new Request(it));
    }
}

void PageReplacementAlgorithmTester::run() {
    auto *optimal = new Optimal(this->requestList);
    cout << endl << "Optimal page replacement algorithm 最佳页面置换算法:" << endl;
    this->run(optimal);
    auto *fifo = new FIFO();
    cout << endl << "FIFO page replacement algorithm 先进先出页面置换算法:" << endl;
    this->run(fifo);
    auto *lru = new LRU();
    cout << endl << "LRU page replacement algorithm 最近最少使用置换算法:" << endl;
    this->run(lru);
}

void PageReplacementAlgorithmTester::run(PageReplacementAlgorithm *pageReplacementAlgorithm) {
    this->memory->clear();
    this->memory->setPageReplacementAlgorithm(pageReplacementAlgorithm);
    auto *result = new list<Memory *>();
    for (auto it:*this->requestList) {
        this->memory->respond(it);
        result->push_back(this->memory->getSnapshot());
    }
    this->print(result);
}

void PageReplacementAlgorithmTester::print(list<Memory *> *result) {
    this->printRequest();
    this->printLine(result);
    for (unsigned long i = 0; i < result->front()->getBlocks()->size(); i++) {
        this->printPageNumber(result, i);
        this->printLine(result);
    }
    this->printRequestResult(result);
}

void PageReplacementAlgorithmTester::printRequest() {
    for (auto it = this->requestList->begin(); it != this->requestList->end(); it++) {
        cout << (*it)->getPageNumber();
        if (it != --this->requestList->end()) {
            cout << "   ";
        } else {
            cout << endl;
        }
    }
}

void PageReplacementAlgorithmTester::printLine(list<Memory *> *result) {
    for (auto it = result->begin(); it != result->end(); it++) {
        if ((*it)->getRequestResult() != Memory::RequestResultEnum::SUCCESS) {
            cout << "+-+";
        } else if (it != --result->end()) {
            cout << "   ";
        }
        if (it != --result->end()) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

void PageReplacementAlgorithmTester::printPageNumber(list<Memory *> *result, unsigned long index) {
    for (auto it = result->begin(); it != result->end(); it++) {
        if ((*it)->getRequestResult() != Memory::RequestResultEnum::SUCCESS) {
            unsigned long i = 0;
            for (auto itBlk:*(*it)->getBlocks()) {
                if (i == index) {
                    if (itBlk->isEmpty()) {
                        cout << "| |";
                    } else {
                        cout << "|" << itBlk->getPageNumber() << "|";
                    }
                    break;
                } else {
                    i++;
                }
            }
        } else if (it != --result->end()) {
            cout << "   ";
        }
        if (it != --result->end()) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

void PageReplacementAlgorithmTester::printRequestResult(list<Memory *> *result) {
    unsigned long replaceCount = 0;
    for (auto it = result->begin(); it != result->end(); it++) {
        if ((*it)->getRequestResult() != Memory::RequestResultEnum::REPLACED) {
            cout << "   ";
        } else {
            cout << " ^ ";
            replaceCount++;
        }
        if (it != --result->end()) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    cout << "Replacement count 缺页次数: " << replaceCount << endl;
}
