//
// Created by Ivan on 25/07/2023.
//

#ifndef NECERINI_LABPROGRAMMAZIONE_ITEM_H
#define NECERINI_LABPROGRAMMAZIONE_ITEM_H

#include <string>
#include <exception>
#include <stdexcept>
using namespace std;

class Item {
public:
    Item(string s, string c, int q=1):  itemName(move(s)),itemCategory(move(c)){
        if(q>=0)
            itemQta=q;
        else
            throw out_of_range("Item quantity passed is not positive");
        isCompleted=false;
    }

private:
    string itemName;
    string itemCategory;
    int itemQta;
    bool isCompleted;
};

#endif //NECERINI_LABPROGRAMMAZIONE_ITEM_H
