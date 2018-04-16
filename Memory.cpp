//
// Created by 林庆华 on 2018/4/13.
//

#include "Memory.h"

PageReplacementAlgorithm *Memory::getPageReplacementAlgorithm() const {
    return pageReplacementAlgorithm;
}

void Memory::setPageReplacementAlgorithm(PageReplacementAlgorithm *pageReplacementAlgorithm) {
    Memory::pageReplacementAlgorithm = pageReplacementAlgorithm;
}

Memory::Memory(int blocksCount) {
    this->blocks=new list<Block>(blocksCount,Block());
}
