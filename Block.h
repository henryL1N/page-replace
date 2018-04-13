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

    /**
     * -1 means empty block
     */
    int pageNumber;

public:

    /**
     * Constructor without argument.
     */
    Block();

    /**
     * Get stored page number.
     * @return stored page number
     */
    int getPageNumber();

    /**
     * Load page.
     * @param pageNumber page number to be loaded
     */
    void load(int pageNumber);

    /**
     * Clear page number (set -1).
     */
    void clear();

};

#endif //PAGE_REPLACE_CPP_BLOCK_H
