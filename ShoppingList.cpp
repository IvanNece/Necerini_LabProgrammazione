//
// Created by Ivan on 25/07/2023.
//

#include "ShoppingList.h"

void ShoppingList::attach(Observer* o) {
    observers.push_back(o);
}

void ShoppingList::detach(Observer* o) {
    observers.remove(o);
}

void ShoppingList::notify() {
    for (auto observer : observers) {
        observer->update(shoppingListName);
    }
}

void ShoppingList::addItem(const Item& item) {
    auto itr = shoppingList.find(item.getItemName());
    if (itr != shoppingList.end() && itr->second->getItemCategory() == item.getItemCategory()) {
        // L'oggetto è già presente, aggiorno la quantità
        int result = itr->second->getItemQta() + item.getItemQta();
        itr->second->setItemQta(result);
    } else {
        // L'oggetto non è ancora presente, lo inserisco
        auto itemPtr = std::make_shared<Item>(item);
        shoppingList.insert(std::make_pair(item.getItemName(), itemPtr));
    }

    std::string itemCat = item.getItemCategory();
    bool flag = false;
    for (auto& it : categories) {
        if (it.first == itemCat) {
            // Categoria già presente, aggiorno il numero di oggetti nella categoria
            it.second++;
            flag = true;
            break;
        }
    }
    if (!flag) {
        categories.insert(std::make_pair(itemCat, 1));
    }

    notify();
}


void ShoppingList::removeItem(const string& name) {
    // Trovo l'oggetto con il nome specificato nella mappa shoppingList
    auto itr = shoppingList.find(name);

    if (itr == shoppingList.end()) {
        throw std::invalid_argument("Invalid item name");
    } else {
        // Trovo la categoria dell'oggetto nella mappa categories
        auto& category = itr->second->getItemCategory();
        auto itCategory = categories.find(category);

        // Decremento il conteggio degli oggetti nella categoria corrispondente
        itCategory->second--;

        // Se il conteggio degli oggetti nella categoria diventa 0, rimuovo la categoria dalla mappa categories
        if (itCategory->second == 0) {
            categories.erase(itCategory);
        }

        // Imposto la quantità dell'oggetto a 0 e lo rimuovo dalla mappa shoppingList
        itr->second->setItemQta(0);
        shoppingList.erase(itr);

        // Notifico gli osservatori della modifica alla lista della spesa
        notify();
    }
}


void ShoppingList::setBought(const string& name) {
    auto itr = shoppingList.find(name);

    if (itr != shoppingList.end()) {
        bool isCompleted = itr->second->isBoughtStatus();
        if (isCompleted) {
            itr->second->sell(); // Cambia da completato a non completato
        } else {
            itr->second->buy(); // Cambia da non completato a completato
        }

        notify();
    } else {
        throw std::invalid_argument("Invalid item name");
    }
}


int ShoppingList::getNotBoughtCount() const {
    int count = 0;
    for (const auto& item : shoppingList) {
        if (!item.second->isBoughtStatus()) {
            count += item.second->getItemQta();
        }
    }
    return count;
}


void ShoppingList::printNotBought() const {
    int totalNotBought = 0;
    cout << "Items not bought in " << shoppingListName << ":" << endl;

    for (const auto& itr : categories) {
        const string& category = itr.first;
        int categoryNotBought = 0;
        bool first = true;

        if (itr.second != 0) {
            for (const auto& item : shoppingList) {
                if (item.second->getItemCategory() == category && !item.second->isBoughtStatus()) {
                    if (first) {
                        cout << "Category: " << category << endl;
                        first = false;
                    }

                    cout << "- " << item.first << " (" << item.second->getItemQta() << ")" << endl;
                    categoryNotBought += item.second->getItemQta();
                }
            }
        }

        totalNotBought += categoryNotBought;
    }

    cout << "Total number of items not bought: " << totalNotBought << endl;
    cout << endl;
}


const string& ShoppingList::getShoppingListName() const {
    return shoppingListName;
}

void ShoppingList::setShoppingListName(const string& shoppingListName) {
    this->shoppingListName = shoppingListName;
}

const map<string, shared_ptr<Item>>& ShoppingList::getShoppingList() const {
    return shoppingList;
}

const list<Observer*>& ShoppingList::getObservers() const {
    return observers;
}

const map<string, int>& ShoppingList::getCategories() const {
    return categories;
}