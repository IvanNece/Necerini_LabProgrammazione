//
// Created by Ivan on 25/07/2023.
//

#ifndef NECERINI_LABPROGRAMMAZIONE_SUBJECT_H
#define NECERINI_LABPROGRAMMAZIONE_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject()=default;

    virtual void attach(Observer* o)=0;

    virtual void detach(Observer* o)=0;

    virtual void notify()=0;
};

#endif //NECERINI_LABPROGRAMMAZIONE_SUBJECT_H
