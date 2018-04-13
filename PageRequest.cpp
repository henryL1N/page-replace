//
// Created by 林庆华 on 11/04/2018.
//

#include "PageRequest.h"

PageRequest::PageRequest(int *pageNumberArray, int requestsCount) {
    PageRequest *pageRequest;

    previous=nullptr;
    next= nullptr;
    pageNumber = pageNumberArray[0];
    pageRequest = this;
    if(requestsCount>1){
        pageRequest->setNext(new PageRequest(++pageNumberArray, --requestsCount));
        pageRequest->getNext()->setPrevious(pageRequest);
    }

}

PageRequest *PageRequest::getPrevious() {
    return previous;
}

void PageRequest::setPrevious(PageRequest *previous) {
    this->previous = previous;
}

PageRequest *PageRequest::getNext() {
    return next;
}

void PageRequest::setNext(PageRequest *next) {
    this->next = next;
}

int PageRequest::getPageNumber() {
    return pageNumber;
}

void PageRequest::setPageNumber(int pageNumber) {
    this->pageNumber = pageNumber;
}
