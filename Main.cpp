//
// Created by 林庆华 on 11/04/2018.
//

#include "Main.h"

int main() {
    int blocksCount;
    do {
        blocksCount = userInput<int>("Please input blocks count (>0): ");
    } while (blocksCount <= 0);
    char *requestNumberString;
    int pageRequestArray[500];
    int pageRequestCount = 0;
    bool isValidRequest = false;
    do {
        requestNumberString = userInput<char *>("Please input request sequence(separated by comma): ");
        pageRequestCount = convertStringToIntegerArray(requestNumberString, pageRequestArray);
        if (pageRequestCount > 1) {
            isValidRequest = true;
        }
    } while (!isValidRequest);
    //7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1

    Blocks *blocks = new Blocks(blocksCount);

    PageRequest *request=new PageRequest(pageRequestArray,pageRequestCount);

    blocks->replaceByOptimal(request);

    blocks->clear();

    blocks->replaceByFIFO(request);

//    blocks->print();

}