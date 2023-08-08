//
// Created by Ivan on 25/07/2023.
//

#ifndef NECERINI_LABPROGRAMMAZIONE_USER_H
#define NECERINI_LABPROGRAMMAZIONE_USER_H

#include "ShoppingList.h"
#include "Observer.h"
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <list>
#include <map>
#include <memory>
#include <algorithm>
using namespace std;

class User: public Observer{
public:
    User();
    User(const string& userName);
    virtual ~User();

    virtual void update(const string& listName) override;

    void addShoppingList(ShoppingList& shoppingList);
    void removeShoppingList(const string& name);

    const map<string, shared_ptr<ShoppingList>>& getMyLists() const;

    const string &getUserName() const;


private:
    string userName;
    // le liste sono le shoppingList (Subject), un User può avere più liste della spesa ovvero più Subject
    map<string, shared_ptr<ShoppingList>> myLists;
};


#endif //NECERINI_LABPROGRAMMAZIONE_USER_H
