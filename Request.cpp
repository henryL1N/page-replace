//
// Created by 林庆华 on 2018/4/16.
//

#include "Request.h"

int Request::getPageNumber() const {
    return pageNumber;
}

void Request::setPageNumber(int pageNumber) {
    Request::pageNumber = pageNumber;
}

Request::Request(int pageNumber) : pageNumber(pageNumber) {
    this->setPageNumber(pageNumber);
}
