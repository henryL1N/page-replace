//
// Created by 林庆华 on 11/04/2018.
//

#include "Block.h"

Block::Block() {
    previous = nullptr;
    next = nullptr;
    pageNumber = -1;
}

Block *Block::getPrevious() {
    return previous;
}

void Block::setPrevious(Block *previous) {
    this->previous = previous;
}

Block *Block::getNext() {
    return next;
}

void Block::setNext(Block *next) {
    this->next = next;
}

int Block::getPageNumber() {
    return pageNumber;
}

void Block::setPageNumber(int pageNumber) {
    this->pageNumber = pageNumber;
}

void Block::clear() {
    pageNumber = -1;
}
