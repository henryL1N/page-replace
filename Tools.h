//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_TOOLS_H
#define MAIN_CPP_TOOLS_H


#include <cstdlib>
#include <iostream>
#include <list>

using namespace std;

class Tools {
public:

    template<typename T>
    static T userInput(const char *prompt) {
        T out;
        if (typeid(T) == typeid(char *)) {
            void *p = malloc(255);
            long l = (long) p;
            out = (T) l;
        }
        while (1) {
            cout << prompt;
            if (!(cin >> out) || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        }
        return out;
    }

    static list<int> *convertStringToIntegerList(char *string, char separator){
        list<int> *ret=new list<int>;
        //converted value
        int value = 0;
        //sign 0:unknown(none of '+' or '-' or number was found); 1:number or '+' found in first digit; -1:'-' found in first digit
        int sign = 0;
        //one or more numbers were found
        bool hasNumber = false;
        do {
            if (*string >= '0' && *string <= '9') {
                hasNumber = true;
                if (!sign) {
                    sign = 1;
                }
                value = value * 10 + sign * (int) (*string - '0');
                string++;
            } else if (!sign && *string == '+') {
                sign = 1;
                string++;
            } else if (!sign && *string == '-') {
                sign = -1;
                string++;
            } else if (hasNumber && *string == separator) {
                ret->push_back(value);
                string++;
                list<int> *subList = convertStringToIntegerList(string, separator);
                if (subList->empty()) {
                    ret->clear();
                }else {
                    ret->insert(ret->end(), subList->begin(), subList->end());
                }
                delete subList;
                break;
            } else if (hasNumber && *string == 0) {
                ret->push_back(value);
                break;
            } else {
                break;
            }
        } while (true);
        return ret;
    }
};

#endif //MAIN_CPP_TOOLS_H
