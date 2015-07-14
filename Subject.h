//
// Created by jobair_hassan on 12/07/15.
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include <set>

class Observer;

class Subject {
public:
    void subscribe(Observer *);
    void unsubscribe(Observer *);
protected:
    void notify();
private:
    typedef std::set<Observer *> Observers;
    Observers observers_;

}; // Subject


#endif //SUBJECT_H