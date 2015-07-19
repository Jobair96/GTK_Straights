#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer {
public:
    virtual void update() = 0; //pure virtual update function for Observer pattern
};

#endif //OBSERVER_H
