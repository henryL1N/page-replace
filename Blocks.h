//
// Created by 林庆华 on 11/04/2018.
//

#ifndef PAGE_REPLACE_CPP_BLOCKS_H
#define PAGE_REPLACE_CPP_BLOCKS_H

#include <iostream>
#include "PageRequest.h"
#include "Block.h"

/**
 * Blocks state
 */
class Blocks {

private:

    Blocks *previous;

    Blocks *next;

//    PageRequest *pageRequest;

    Block *headBlock;

    enum RequestResultEnum {

        SUCCESS,//successfully requested in recently stored pages

        LOADED,//requested page was not stored in the blocks and one or more blocks are empty

        REPLACE_REQUIRE//requested page was not stored in the blocks and none of them is empty

    };

    /**
     * Print line according to pageRequest.
     * @param pageRequest
     */
    void printLineWithPageRequest(PageRequest *pageRequest);

    /**
     * Print page number by block index.
     * @param blockIndex
     */
    void printPageNumbersByBlockIndex(int blockIndex);

public:

    /**
     * Construct blocks according blocks count.
     * @param blocksCount blocks count
     */
    explicit Blocks(int blocksCount);

    /**
     * Construct blocks by previous blocks.
     * @param previousBlocks previous blocks
     */
    explicit Blocks(Blocks *previousBlocks);

    /**
     * Get previous blocks state.
     * @return pointer of previous blocks state
     */
    Blocks *getPrevious();

    /**
     * Set previous blocks state.
     * @param previous pointer of previous blocks state
     */
    void setPrevious(Blocks *previous);

    /**
     * Get next blocks state.
     * @return pointer of next blocks state
     */
    Blocks *getNext();

    /**
     * Set next blocks state.
     * @param previous pointer of next blocks state
     */
    void setNext(Blocks *next);

    /**
     * Get page request of this blocks state.
     * @return page request of this blocks state
     */
    PageRequest *getPageRequest();

    /**
     * Set page request of this blocks state
     * @param pageRequest page request of this blocks state
     */
    void setPageRequest(PageRequest *pageRequest);

    /**
     * Get the first block of this blocks state.
     * @return the first block of this blocks state
     */
    Block *getHeadBlock();

    /**
     * Set the first block of this blocks state.
     * @param headBlock the first block of this blocks state
     */
    void setHeadBlock(Block *headBlock);

    /**
     * Replace block with "Optimal" algorithm.
     * Replace the block that contains the page which will be request in the furthest future.
     * @param pageRequest pointer of the first page request
     */
    void replaceByOptimal(PageRequest *pageRequest);

    /**
     * Replace block with "FIFO(First In First Out)" algorithm.
     * Replace the block that loaded before others.
     * @param pageRequest pointer of the first page request
     */
    void replaceByFIFO(PageRequest *pageRequest);

    /**
     * Replace block with "LRU(Least Recently Used)" algorithm.
     * Replace the block that has the earliest last request time.
     * @param pageRequest pointer of the first page request
     */
    void replaceByLRU(PageRequest *pageRequest);

    Block *getBlockByOptimal(PageRequest *pageRequest);

    /**
     * Request specified page in the blocks.
     * @param pageRequest pointer of page request
     * @return request result
     */
    RequestResultEnum request(PageRequest *pageRequest);

    /**
     * Print blocks with page request;
     */
    void printWithPageRequest(PageRequest *pageRequest);

};


#endif //PAGE_REPLACE_CPP_BLOCKS_H
