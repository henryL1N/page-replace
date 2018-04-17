//
// Created by 林庆华 on 2018/4/13.
//

#include "Memory.h"

void Memory::setPageReplacementAlgorithm(PageReplacementAlgorithm *pageReplacementAlgorithm) {
    Memory::pageReplacementAlgorithm = pageReplacementAlgorithm;
}

Memory::Memory(unsigned long blocksCount) {
    this->blocks = new list<Block*>(blocksCount, new Block());
}

Memory::RequestResultEnum Memory::getRequestResult() const {
    return requestResult;
}

Block *Memory::response(Request *request) {
    this->pageReplacementAlgorithm->monitor(request);
    Block *block = nullptr;
    bool hasEmptyBlock = false;
    bool pageFound = false;
    for (auto &it:*this->blocks) {
        if (it->getPageNumber() == request->getPageNumber()) {
            pageFound = true;
            this->requestResult = Memory::RequestResultEnum::SUCCESS;
            block = it;
            break;
        } else if (!hasEmptyBlock && it->getPageNumber() == Block::EMPTY) {
            hasEmptyBlock = true;
            block = it;
        }
    }
    if (!pageFound) {
        if (hasEmptyBlock) {
            block->load(request->getPageNumber());
            this->requestResult = Memory::RequestResultEnum::LOADED;
        } else {
            block = this->pageReplacementAlgorithm->replace(this->blocks);
            this->requestResult = Memory::RequestResultEnum::REPLACED;
        }
    }
    return block;
}
