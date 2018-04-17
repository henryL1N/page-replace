//
// Created by 林庆华 on 11/04/2018.
//

#ifndef PAGE_REPLACE_CPP_BLOCK_H
#define PAGE_REPLACE_CPP_BLOCK_H


/**
 * Block
 */
class Block {

public:

    static const int EMPTY = -1;

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

    explicit Block(int pageNumber);

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

    /**
     * Block is empty.
     * @return true if it is empty
     */
    bool isEmpty();

};


#endif //PAGE_REPLACE_CPP_BLOCK_H
