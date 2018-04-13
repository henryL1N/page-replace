//
// Created by 林庆华 on 11/04/2018.
//

#ifndef PAGE_REPLACE_CPP_REQUEST_H
#define PAGE_REPLACE_CPP_REQUEST_H

/**
 * Page request
 */
class PageRequest {

private:

    PageRequest *previous;

    PageRequest *next;

    int pageNumber;

public:

    /**
     * Construct page request by page number array.
     * @param pageNumberArray array of page numbers
     * @param requestsCount count of requests
     */
    PageRequest(int *pageNumberArray, int requestsCount);

    /**
     * Get previous request.
     * @return pointer of previous request
     */
    PageRequest *getPrevious();

    /**
     * Set previous request.
     * @param previous pointer of previous request
     */
    void setPrevious(PageRequest *previous);

    /**
     * Get next request.
     * @return pointer of next request
     */
    PageRequest *getNext();

    /**
     * Set next request.
     * @param previous pointer of next request
     */
    void setNext(PageRequest *next);

    /**
     * Get requested page number.
     * @return requested page number
     */
    int getPageNumber();

    /**
     * Set requested page number.
     * @param pageNumber requested page number
     */
    void setPageNumber(int pageNumber);

};


#endif //PAGE_REPLACE_CPP_REQUEST_H
