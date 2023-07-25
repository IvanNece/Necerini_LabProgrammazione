//
// Created by Ivan on 25/07/2023.
//

#ifndef NECERINI_LABPROGRAMMAZIONE_OBSERVER_H
#define NECERINI_LABPROGRAMMAZIONE_OBSERVER_H

#include <string>
using namespace std;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(const string& listName) = 0;
};

#endif //NECERINI_LABPROGRAMMAZIONE_OBSERVER_H
