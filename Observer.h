//
// Created by jobair_hassan on 12/07/15.
//

#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer {
public:
    virtual void update() = 0;
};

#endif //OBSERVER_H
