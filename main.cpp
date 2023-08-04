#include <iostream>
#include <string>
#include <stdexcept>
#include "Subject.h"
#include "ShoppingList.h"
#include "User.h"
using namespace std;


// Funzione per stampare una ShoppingList
void print(const ShoppingList& sl) {
    cout << "Name of the shopping list: " << sl.getShoppingListName() << endl << endl;

    for (const auto& categoryEntry : sl.getCategories()) {
        const string& category = categoryEntry.first;
        int categoryNotBought = 0;

        if (categoryEntry.second != 0) {
            cout << "Category: " << category << endl;

            for (const auto& itemEntry : sl.getShoppingList()) {
                const shared_ptr<Item>& item = itemEntry.second;

                if (item->getItemCategory() == category && !item->isBoughtStatus()) {
                    cout << "- " << item->getItemName() << " (" << item->getItemQta() << ")";
                    cout << (item->isBoughtStatus() ? "       Bought" : "       Not bought") << endl;
                    categoryNotBought += item->getItemQta();
                }
            }
            cout << endl;
        }
    }

    cout << "Total number of items not bought: " << sl.getNotBoughtCount() << endl << endl;
}

int main() {

    cout << "Welcome to the Shopping List App!" << endl << endl << endl;

    bool isCreationProcessing=true;
    int userChoice;
    map <string,User> users;
    map <string, ShoppingList> shoppingLists;
    map <string, Item> items;


    //------------------------------------------------------------------------------------------------------------------

    cout<<"1) CREATION OF THE SHOPPING LIST "<<endl<<endl;

    while(isCreationProcessing)
    {
        cout << endl << "Choose:" << endl;
        cout << "1. Create a new shopping list" << endl;
        cout << "2. Move on" << endl;
        cin>>userChoice;
        cout<<endl;

        switch (userChoice) {
            case 1 : {
                string shoppingListName;
                cout << "Enter the name of the new shopping list: ";
                cin >> shoppingListName;

                ShoppingList newShoppingList(shoppingListName);
                shoppingLists.insert(make_pair(shoppingListName, newShoppingList));

                cout << "Shopping list \"" << shoppingListName << "\" created." << endl;
                break;
            }

            case 2 : {
                isCreationProcessing=false;
                break;
            }

            default: {
                cout << "Invalid input. Please try again." << endl;
                break;
            }
        }
    }

    //------------------------------------------------------------------------------------------------------------------

    cout << endl << "2) CREATION OF THE ITEMS" << endl << endl;

    isCreationProcessing = true;

    while (isCreationProcessing) {
        cout << endl << "Choose:" << endl;
        cout << "1. Create a new item" << endl;
        cout << "2. Move on" << endl;

        cin >> userChoice;

        switch (userChoice) {
            case 1: {
                string itemName;
                int defaultQuantity = 1;
                string quantityString;
                int quantityInt;
                string itemCategory;

                cout << "Insert item name: ";
                cin >> itemName;
                cout << endl;

                cout << "Insert item category: ";
                cin >> itemCategory;
                cout << endl;

                cout << "Insert quantity (insert 'default' for default quantity): ";
                cin >> quantityString;
                cout << endl;

                if (quantityString == "default") {
                    quantityInt = defaultQuantity;
                } else {
                    try {
                        quantityInt = std::stoi(quantityString);
                    } catch (invalid_argument &e) {
                        quantityInt = defaultQuantity; // Set default quantity if invalid input
                    }
                }

                try {
                    Item i(itemName, itemCategory, quantityInt);
                    items.insert(make_pair(itemName, i));
                } catch (std::out_of_range &e2) {
                    cerr << e2.what() << endl;
                }
                break;
            }

            case 2: {
                isCreationProcessing = false;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }


    //------------------------------------------------------------------------------------------------------------------

    cout << endl << "3) CREATION OF THE USERS" << endl << endl;

    isCreationProcessing = true;

    while (isCreationProcessing) {
        cout << endl << "Choose:" << endl
             << "1. Create a new user" << endl
             << "2. Move on" << endl;

        cin >> userChoice;
        cout << endl;

        switch (userChoice) {
            case 1: {
                string userName;
                cout << "Insert User name: ";
                cin >> userName;

                cout << endl;

                User newUser(userName);
                users.insert(make_pair(userName, newUser));
                break;
            }

            case 2: {
                isCreationProcessing = false;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }


    //------------------------------------------------------------------------------------------------------------------

    cout << endl << endl << "4) YOU CAN NOW EXECUTE OPERATIONS ON THE PREVIOUSLY CREATED LISTS, OBJECTS AND USERS"<<endl;

    bool operations=true;
    while(operations)
    {
        cout << endl;
        cout << "You have the following options:" << endl;
        cout << "1) Add an item to a list" << endl;
        cout << "2) Remove an item from a list (provide list name and item name)" << endl;
        cout << "3) Mark an item as purchased" << endl;
        cout << "4) Add a shopping list to a user's collection" << endl;
        cout << "5) Remove a shopping list from a user's collection" << endl;
        cout << "6) No more operations" << endl;
        cout << endl;

        cin>>userChoice;
        cout<<endl;

        switch (userChoice) {
            case 1 :{
                string listName;
                string itemName;
                cout<<"Insert list name:"<<endl;
                cin>>listName;
                cout<<"Insert item name:"<<endl;
                cin>>itemName;

                auto itrl=shoppingLists.find(listName);
                auto itrn=items.find(itemName);

                try {
                    if(itrl==shoppingLists.end()||itrn==items.end())
                        throw std::invalid_argument("Invalid list name or invalid item name");
                    else
                    {
                        itrl->second.addItem(itrn->second);
                    }
                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }

            case 2: {
                string itemName;
                string listName;

                cout<<"Insert list name:"<<endl;
                cin>>listName;
                cout<<"Insert item name:"<<endl;
                cin>>itemName;

                auto itrl=shoppingLists.find(listName);
                auto itrn=items.find(itemName);

                try {
                    if (itrl == shoppingLists.end() || itrn == items.end())
                        throw std::invalid_argument("Invalid list name or invalid item name");
                    else
                        itrl->second.removeItem(itemName);

                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }

            case 3: {
                string itemName;
                string listName;

                cout<<"Insert list name:"<<endl;
                cin>>listName;
                cout<<"Insert item name:"<<endl;
                cin>>itemName;

                auto itrl=shoppingLists.find(listName);
                auto itrn=items.find(itemName);

                try {
                    if (itrl == shoppingLists.end() || itrn == items.end())
                        throw std::invalid_argument("Invalid list name or invalid item name");
                    else
                        itrl->second.setBought(itemName);

                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }

            case 4: {
                string listName;
                string userName;

                cout<<"Insert list name:"<<endl;
                cin>>listName;
                cout<<"Insert user name:"<<endl;
                cin>>userName;

                auto itrl=shoppingLists.find(listName);
                auto itru=users.find(userName);

                try {
                    if(itrl==shoppingLists.end() || itru==users.end())
                        throw std::invalid_argument("Invalid list name or invalid user name");
                    else
                    {
                        itru->second.addShoppingList(itrl->second);
                    }
                }catch(std::invalid_argument& e){
                    cerr<<e.what()<<endl;
                }
                break;
            }

            case 5: {
                string listName;
                string userName;

                cout<<"Insert list name:"<<endl;
                cin>>listName;
                cout<<"Insert user name:"<<endl;
                cin>>userName;

                auto itrl=shoppingLists.find(listName);
                auto itru=users.find(userName);

                try {
                    if (itrl == shoppingLists.end() || itru == users.end())
                        throw std::invalid_argument("Invalid list/user name");
                    else {
                        itru->second.removeShoppingList(listName);
                    }
                } catch (std::invalid_argument &e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 6: {
                operations=false;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    //------------------------------------------------------------------------------------------------------------------

    cout << endl << endl << "5) REVIEW YOUR CREATIONS (USERS, LISTS, ITEMS)" << endl;

    for (const auto &userPair : users) {
        cout << endl;
        cout << "User name: " << userPair.first << endl;

        for (const auto &listPair : userPair.second.getMyLists()) {
            cout << endl;
            print(*listPair.second);
        }
    }

    //------------------------------------------------------------------------------------------------------------------

    return 0;
}


