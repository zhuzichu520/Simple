//
// Created by Administrator on 2021/6/6 0006.
//

#ifndef SIMPLE_TOOLDATE_H
#define SIMPLE_TOOLDATE_H

class ToolDate {
public:
    ToolDate();

    static QString getCurrTimeStr();

    static QString getCurrDateTimeStr(QString formatStr = "yyyy-MM-dd hh:mm:ss");
};

#endif //SIMPLE_TOOLDATE_H
