//
// Created by Ivan on 25/07/2023.
//

#ifndef NECERINI_LABPROGRAMMAZIONE_SHOPPINGLIST_H
#define NECERINI_LABPROGRAMMAZIONE_SHOPPINGLIST_H

#include "Observer.h"
#include "Subject.h"
#include "Item.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <map>
#include <list>
#include <exception>
#include <stdexcept>
using namespace std;

class ShoppingList: public Subject{
public:
    ShoppingList(const string& shoppingListName) : shoppingListName(shoppingListName) {}

    void attach(Observer* o) override;
    void detach(Observer* o) override;
    void notify() override;

    void addItem(const Item& item);
    void removeItem(const string& name);
    void setBought(const string& name);

    int getNotBoughtCount() const;
    void printNotBought() const;

    const string& getShoppingListName() const;
    void setShoppingListName(const string& shoppingListName);

    const map<string, shared_ptr<Item>>& getShoppingList() const;
    const list<Observer*>& getObservers() const;
    const map<string, int>& getCategories() const;

    virtual ~ShoppingList()=default;

private:
    list<Observer*> observers;
    map<string, shared_ptr<Item>> shoppingList;
    map<string, int> categories;
    string shoppingListName;
};

#endif //NECERINI_LABPROGRAMMAZIONE_SHOPPINGLIST_H
