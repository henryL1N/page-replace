//
// Created by 林庆华 on 11/04/2018.
//

#ifndef PAGE_REPLACE_CPP_BLOCK_H
#define PAGE_REPLACE_CPP_BLOCK_H

#include "PageRequest.h"

/**
 * Block
 */
class Block {

private:

    Block *previous;

    Block *next;

    /**
     * -1 means empty block
     */
    int pageNumber;

//    int loadTime;

//    int accessTime;

public:

    /**
     * Constructor without argument.
     */
    Block();

    /**
     * Get previous block.
     * @return pointer of previous block
     */
    Block *getPrevious();

    /**
     * Set previous block.
     * @param previous pointer of previous block
     */
    void setPrevious(Block *previous);

    /**
     * Get next block.
     * @return pointer of next block
     */
    Block *getNext();

    /**
     * Set next block.
     * @param next pointer of next block
     */
    void setNext(Block *next);

    /**
     * Get stored page number.
     * @return stored page number
     */
    int getPageNumber();

    /**
     * Set stored page number.
     * @param pageNumber page number to be stored
     */
    void setPageNumber(int pageNumber);

    PageRequest *getNextRequestOfSamePage(PageRequest *pageRequest);

};

#endif //PAGE_REPLACE_CPP_BLOCK_H
