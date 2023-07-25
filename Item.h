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
            throw std::out_of_range("Item quantity passed is not positive");
        isBought=false;
    }

    const string &getItemName() const {
        return itemName;
    }

    const string &getItemCategory() const {
        return itemCategory;
    }

    int getItemQta() const {
        return itemQta;
    }

    void setItemQta(int itemQta) {
        if(itemQta>=0)
            Item::itemQta = itemQta;
        else
            throw std::out_of_range("Item quantity passed is not positive");
    }

    void buy(){
        isBought=true;
    }

    void sell(){
        isBought=false;
    }

    bool isBoughtStatus() const {
        return isBought;
    }


private:
    string itemName;
    string itemCategory;
    int itemQta;
    bool isBought;
};

#endif //NECERINI_LABPROGRAMMAZIONE_ITEM_H
