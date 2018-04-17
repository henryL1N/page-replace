//
// Created by 林庆华 on 2018/4/13.
//

#include "Memory.h"

void Memory::setPageReplacementAlgorithm(PageReplacementAlgorithm *pageReplacementAlgorithm) {
    Memory::pageReplacementAlgorithm = pageReplacementAlgorithm;
}

Memory::Memory(unsigned long blocksCount) : Memory() {
    for (; blocksCount > 0; blocksCount--) {
        this->blocks->push_back(new Block());
    }
}

Memory::RequestResultEnum Memory::getRequestResult() const {
    return requestResult;
}

Block *Memory::response(Request *request) {
    this->pageReplacementAlgorithm->monitor(request);
    bool hasEmptyBlock = false;
    bool pageFound = false;
    for (auto &it:*this->blocks) {
        if (it->getPageNumber() == request->getPageNumber()) {
            pageFound = true;
            this->requestResult = Memory::RequestResultEnum::SUCCESS;
            this->respondedBlock = it;
            break;
        } else if (!hasEmptyBlock && it->isEmpty()) {
            hasEmptyBlock = true;
            this->respondedBlock = it;
        }
    }
    if (!pageFound) {
        if (hasEmptyBlock) {
            this->respondedBlock->load(request->getPageNumber());
            this->requestResult = Memory::RequestResultEnum::LOADED;
        } else {
            this->respondedBlock = this->pageReplacementAlgorithm->replace(this->blocks);
            this->requestResult = Memory::RequestResultEnum::REPLACED;
        }
    }
    return this->respondedBlock;
}

Memory *Memory::getSnapshot() {
    auto *snapshot = new Memory();
    snapshot->requestResult = this->requestResult;
    for (auto it:*this->blocks) {
        snapshot->blocks->push_back(new Block(it->getPageNumber()));
        if (this->respondedBlock == it) {
            snapshot->respondedBlock = snapshot->blocks->back();
        }
    }
    return snapshot;
}

Memory::Memory() {
    this->blocks = new list<Block *>();
    this->clear();
    this->pageReplacementAlgorithm = nullptr;
}

list<Block *> *Memory::getBlocks() const {
    return this->blocks;
}

void Memory::clear() {
    for (auto it:*this->blocks) {
        it->clear();
    }
    this->requestResult = Memory::RequestResultEnum::NONE;
    this->respondedBlock = nullptr;
}
