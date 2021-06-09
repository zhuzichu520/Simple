#ifndef SIMPLE_BASEACTIVITY_H
#define SIMPLE_BASEACTIVITY_H

#include <QObject>

class BaseActivity : QObject {
    Q_OBJECT
public:
    explicit BaseActivity(QObject *parent = nullptr);
};

#endif //SIMPLE_BASEACTIVITY_H
