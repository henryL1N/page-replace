//
// Created by 林庆华 on 2018/4/16.
//

#ifndef MAIN_CPP_REQUEST_H
#define MAIN_CPP_REQUEST_H

/**
 * Page request
 * 页面请求
 */
class Request {

private:

    /**
     * page number
     * 页面编号
     */
    int pageNumber;

public:

    /**
     * Construct with page number.
     * 以页面编号构造页面请求。
     * @param pageNumber page number 页面编号
     */
    explicit Request(int pageNumber);

    /**
     * Get page number.
     * 获取页面编号。
     * @return page number 页面编号
     */
    int getPageNumber() const;

};


#endif //MAIN_CPP_REQUEST_H
