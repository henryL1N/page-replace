//
// Created by 林庆华 on 2018/4/16.
//

#include "Request.h"

Request::Request(int pageNumber) {
    this->pageNumber = pageNumber;
}

int Request::getPageNumber() const {
    return this->pageNumber;
}
