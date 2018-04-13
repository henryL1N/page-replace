//
// Created by 林庆华 on 12/04/2018.
//

#ifndef PAGE_REPLACE_CPP_MAIN_H
#define PAGE_REPLACE_CPP_MAIN_H

#include <iostream>
#include "PageRequest.h"
#include "Block.h"
#include "Blocks.h"

using namespace std;

template <typename T>
T userInput(const char *prompt)
{
    T out;
    if (typeid(T) == typeid(char*))
    {
        void* p = malloc(255);
        long l = (long)p;
        out = (T)l;
    }
    while (1)
    {
        cout << prompt;
        if (!(cin >> out) || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else break;
    }
    return out;
}

int convertStringToIntegerArray(char *string, int *intArray){
    if(*string==0) {
        return 0;
    }else if(*string==',') {
        return -1;
    }else if(*string==' '){
        string++;
        return convertStringToIntegerArray(string, intArray);
    }else{
        do{
            if(*string>='0'&&*string<='9'){
                *intArray=*intArray*10+(int)(*string-'0');
                string++;
            }else if(*string==','){
                string++;
                intArray++;
                int nextReturn=convertStringToIntegerArray(string, intArray);
                if(nextReturn>=0) {
                    return 1 + nextReturn;
                }else{
                    return -1;
                }
            }else if(*string==0){
                return 1;
            }else{
                return -1;
            }
        }while(true);
    }
}

#endif //PAGE_REPLACE_CPP_MAIN_H
