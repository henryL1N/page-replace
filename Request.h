//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_REQUEST_H
#define MAIN_CPP_REQUEST_H


class Request {

private:

    int pageNumber;

public:

    explicit Request(int pageNumber);

    int getPageNumber() const;

    void setPageNumber(int pageNumber);

};


#endif //MAIN_CPP_REQUEST_H
