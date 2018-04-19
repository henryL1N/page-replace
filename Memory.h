//
// Created by 林庆华 on 2018/4/13.
//

#ifndef MAIN_CPP_MEMORY_H
#define MAIN_CPP_MEMORY_H


#include <list>
#include "Block.h"
#include "Request.h"
#include "PageReplacementAlgorithm.h"

using namespace std;

/**
 * Memory
 */
class Memory {

public:

    /**
     * Request result enumeration.
     */
    enum RequestResultEnum {

        /**
         * Never requested.
         */
        NONE,

        /**
         * Requested page was found in blocks.
         */
        SUCCESS,

        /**
         * Requested page was not found in blocks and has been loaded to the empty block.
         */
        LOADED,

        /**
         * Requested page was not found in blocks and has replaced the page in block.
         */
        REPLACED

    };

private:

    /**
     * Pointer of block list.
     */
    list<Block *> *blocks;

public:

    /**
     * Get pointer of block list.
     * @return pointer of block list
     */
    list<Block *> *getBlocks() const;

private:

    /**
     * Request result.
     */
    RequestResultEnum requestResult;

    /**
     * Pointer of page replacement algorithm.
     */
    PageReplacementAlgorithm *pageReplacementAlgorithm;

    /**
     * Pointer of responded block.
     */
    Block *respondedBlock;

public:

    /**
     * Constructor without argument.
     */
    Memory();

    /**
     * Constructor with specified amount of blocks.
     * @param blocksCount blocks amount
     */
    explicit Memory(unsigned long blocksCount);

    /**
     * Get the result of last request.
     * @return result of last request
     */
    RequestResultEnum getRequestResult() const;

    /**
     * Set specified page replacement algorithm.
     * @param pageReplacementAlgorithm specified page replacement algorithm
     */
    void setPageReplacementAlgorithm(PageReplacementAlgorithm *pageReplacementAlgorithm);

    /**
     * Respond page request.
     * @param request pointer of page request
     * @return pointer of block that contains the requested page
     */
    Block *respond(Request *request);

    Memory *getSnapshot();

    /**
     * Reset to state of just initialized.
     */
    void clear();

};


#endif //MAIN_CPP_MEMORY_H
