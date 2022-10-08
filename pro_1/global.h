#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>

#include <QtDebug>

class message     //新建一个类存放全局变量
{
public:
     static QString display;
     static QString gpwd;
     static int gid;
     static int STUCHOOSE;
     static QString gdepart;
};
#endif // GLOBAL_H
