//
// Created by 林庆华 on 11/04/2018.
//

#include "Blocks.h"

using namespace std;

Blocks::Blocks(int blocksCount) {
    previous= nullptr;
    next=nullptr;
    if (blocksCount <= 0) {
        cout << "Blocks construction fail! Blocks count less than 1." << endl;
    }
    Block *block;
    block = new Block();
    headBlock = block;
    for (int i = blocksCount - 1; i > 0; i--) {
        block->setNext(new Block());
        block->getNext()->setPrevious(block);
        block = block->getNext();
    }
}

Blocks::Blocks(Blocks *previousBlocks) {
    previous = previousBlocks;
    next= nullptr;
    if (previousBlocks->getHeadBlock()) {
        headBlock = new Block();
        Block *oldBlock = previousBlocks->getHeadBlock();
        Block *newBlock = headBlock;
        newBlock->setPageNumber(oldBlock->getPageNumber());
        while(oldBlock->getNext()){
            newBlock->setNext(new Block());
            newBlock->getNext()->setPrevious(newBlock);
            newBlock->getNext()->setPageNumber(oldBlock->getNext()->getPageNumber());

            oldBlock=oldBlock->getNext();
            newBlock=newBlock->getNext();
        }

    }


}

Blocks *Blocks::getPrevious() {
    return previous;
}

void Blocks::setPrevious(Blocks *previous) {
    this->previous = previous;
}

Blocks *Blocks::getNext() {
    return next;
}

void Blocks::setNext(Blocks *next) {
    this->next = next;
}

//PageRequest *Blocks::getPageRequest() {
//    return pageRequest;
//}

//void Blocks::setPageRequest(PageRequest *pageRequest) {
//    this->pageRequest = pageRequest;
//}

Block *Blocks::getHeadBlock() {
    return headBlock;
}

void Blocks::setHeadBlock(Block *headBlock) {
    this->headBlock = headBlock;
}

void Blocks::replaceByOptimal(PageRequest *pageRequest) {
    RequestResultEnum requestResult = request(pageRequest);
    if (requestResult == REPLACE_REQUIRE) {
        getBlockByOptimal(pageRequest)->setPageNumber(pageRequest->getPageNumber());
    }
    if (pageRequest->getNext()) {
        next = new Blocks(this);
        next->replaceByOptimal(pageRequest->getNext());
    }
}

Block *Blocks::getBlockByOptimal(PageRequest *pageRequest) {

    class BlockLink {
    private:
        BlockLink *previous;
        BlockLink *next;
        Block *block;
    public:
        explicit BlockLink(Block *block) {
            previous = nullptr;
            this->block = block;
            if (block->getNext()) {
                next = new BlockLink(block->getNext());
                next->previous = this;
            } else {
                next = nullptr;
            }
        };

        /**
         * Get first block link.
         * @return pointer of first block link
         */
        BlockLink *getHead() {
            if (previous) {
                return previous->getHead();
            } else {
                return this;
            }
        }

        /**
         * Get last block link.
         * @return pointer of last block link
         */
        BlockLink *getTail() {
            if (next) {
                return next->getTail();
            } else {
                return this;
            }
        }

        BlockLink *remove(bool returnHead = true) {
            BlockLink *nextOrPrevious = nullptr;
            if (previous) {
                previous->next = next;
                nextOrPrevious = previous;
            }
            if (next) {
                next->previous = previous;
                nextOrPrevious = next;
            }
            delete this;
            if (returnHead && nextOrPrevious) {
                return nextOrPrevious->getHead();
            } else {
                return nextOrPrevious;
            }
        }

        Block *getBlockByOptimal(PageRequest *pageRequest) {
            if (!previous && !next) {
                // If this block is the only one, return this block.
                return block;
            }
            if (block->getPageNumber() == pageRequest->getPageNumber()) {
                // If this block contains the same page number with request, and...
                if (pageRequest->getNext()) {
                    // If exists next request,
                    // remove and get head to recur this method with next request.
                    return remove()->getBlockByOptimal(pageRequest->getNext());
                } else {
                    // Else(not exists next request),
                    // return the head block of the block link after remove.
                    return remove()->block;
                }
            } else {
                // Else(different page number), and...
                if (pageRequest->getNext()) {
                    // If exists next request, and...
                    if (next) {
                        // If exists next block link,
                        // get next block link to recur this method with the same request.
                        return next->getBlockByOptimal(pageRequest);
                    } else {
                        // Else(not exists next block link),
                        // get head to recur this method with next request.
                        return getHead()->getBlockByOptimal(pageRequest->getNext());
                    }
                } else {
                    // Else(not exists next request),
                    // return this block.
                    return block;
                }
            }

        }
    };

    BlockLink *bl=new BlockLink(headBlock);

    Block *ret=bl->getBlockByOptimal(pageRequest);

    delete bl;

    return ret;

}

Blocks::RequestResultEnum Blocks::request(PageRequest *pageRequest) {
    Block *block = headBlock;
    do {
        if (block->getPageNumber() == -1) {
            block->setPageNumber(pageRequest->getPageNumber());
            return LOADED;
        } else if (block->getPageNumber() == pageRequest->getPageNumber()) {
            return SUCCESS;
        } else if (block->getNext()) {
            block = block->getNext();
        } else {
            return REPLACE_REQUIRE;
        }
    } while (true);
}

void Blocks::printWithPageRequest(PageRequest *pageRequest) {
    PageRequest *request = pageRequest;
    do {
        cout << request->getPageNumber();
        if (request->getNext()) {
            cout << "   ";
            request = request->getNext();
        } else {
            cout << endl;
            break;
        }
    } while (true);
    request = pageRequest;
    Block *block = headBlock;
    printLineWithPageRequest(request);
    int blockIndex = 0;
    do {
        do {
            printPageNumbersByBlockIndex(blockIndex);
            if (request->getNext()) {
                cout << " ";
                request = request->getNext();
            } else {
                cout << endl;
                break;
            }
        } while (true);

        printLineWithPageRequest(request);
        if (block->getNext()) {
            blockIndex++;
            block = block->getNext();
        } else {
            break;
        }
    } while (true);
}

void Blocks::printLineWithPageRequest(PageRequest *pageRequest) {
    do {
        cout << "|-|";
        if (pageRequest->getNext()) {
            cout << " ";
            pageRequest = pageRequest->getNext();
        } else {
            cout << endl;
            break;
        }
    } while (true);
}

void Blocks::printPageNumbersByBlockIndex(int blockIndex) {
    Block *block = headBlock;
    if (blockIndex == 0) {
        cout << "|";
        if (block->getPageNumber() == -1) {
            cout << " ";
        } else {
            cout << block->getPageNumber();
        }
        cout << "|";
    } else {
        printPageNumbersByBlockIndex(--blockIndex);
    }
}
