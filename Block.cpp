//
// Created by 林庆华 on 11/04/2018.
//

#include "Block.h"

Block::Block() {
    clear();
}

void Block::load(int pageNumber) {
    this->pageNumber = pageNumber;
}

void Block::clear() {
    this->pageNumber = Block::EMPTY;
}

int Block::getPageNumber() {
    return this->pageNumber;
}
