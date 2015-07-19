#ifndef SUBJECT_H
#define SUBJECT_H

#include <set>

class Observer;

class Subject {
public:
    void subscribe(Observer *); //subscribes an observer to the subject
    void unsubscribe(Observer *); //unsubscribes the observer

protected:
    void notify(); //notifies the observer that the subject has changed

private:
    typedef std::set<Observer *> Observers;
    Observers observers_; //the set of observers subscribed to this subject

}; // Subject


#endif //SUBJECT_H
