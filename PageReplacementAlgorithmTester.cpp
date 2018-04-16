//
// Created by 林庆华 on 2018/4/16.
//

#include "PageReplacementAlgorithmTester.h"
#include "Tools.h"

PageReplacementAlgorithmTester::PageReplacementAlgorithmTester() {
    //input blocks count
    int blocksCount;
    do {
        blocksCount = Tools::userInput<int>("Please input blocks count (>0): ");
    } while (blocksCount <= 0);

    //initialize memory
    this->memory=new Memory(blocksCount);

    //input request sequence
    char *requestNumberString;
    bool isValidRequest = false;
    list<int> *requestNumberList;
    do {
        requestNumberString = Tools::userInput<char *>(
                "Please input request sequence:\n"
                "(0 <= page number <= 9)\n"
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
    this->requestList=new list<Request>;
    for (auto &it : *requestNumberList) {
        this->requestList->push_back(Request(it));
    }

}

void PageReplacementAlgorithmTester::run() {
    this->run(this->optimal);
    this->run(this->fifo);
    this->run(this->lru);
}

void PageReplacementAlgorithmTester::run(PageReplacementAlgorithm *pageReplacementAlgorithm) {

}
