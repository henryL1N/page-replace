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
    bool hasEmptyBlock = false;
    bool pageFound = false;
    for (auto &it:*this->blocks) {
        if (it->getPageNumber() == request->getPageNumber()) {
            pageFound = true;
            this->requestResult = Memory::RequestResultEnum::SUCCESS;
            this->responsedBlock = it;
            break;
        } else if (!hasEmptyBlock && it->getPageNumber() == Block::EMPTY) {
            hasEmptyBlock = true;
            this->responsedBlock = it;
        }
    }
    if (!pageFound) {
        if (hasEmptyBlock) {
            this->responsedBlock->load(request->getPageNumber());
            this->requestResult = Memory::RequestResultEnum::LOADED;
        } else {
            this->responsedBlock = this->pageReplacementAlgorithm->replace(this->blocks);
            this->requestResult = Memory::RequestResultEnum::REPLACED;
        }
    }
    return this->responsedBlock;
}

Memory *Memory::getSnapshot() {
    auto *snapshot=new Memory();
    snapshot->requestResult=this->requestResult;
    for(auto it:*this->blocks){
        snapshot->blocks->push_back(new Block(it->getPageNumber()));
        if (this->responsedBlock == it) {
            snapshot->responsedBlock=snapshot->blocks->back();
        }
    }
    return snapshot;
}

Memory::Memory() {
    this->blocks=new list<Block*>();
    this->responsedBlock= nullptr;
}

list<Block *> *Memory::getBlocks() const {
    return this->blocks;
}
