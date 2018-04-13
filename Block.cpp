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
    pageNumber = -1;
}
