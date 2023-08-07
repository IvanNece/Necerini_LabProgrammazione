//
// Created by Ivan on 07/08/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListSuite:  public::testing::Test{

protected:
protected:

    void SetUp() override {
        s.addItem(ciliegia);
        s.addItem(insalata);
        s.addItem(pane);
    }


    ShoppingList s{"casa"};
    Item ciliegia{"ciliegia","frutta",1};
    Item insalata{"insalata","verdura",1};
    Item pane{"pane","cibo",5};
    User user;
};



TEST_F(ShoppingListSuite, TestParametrizeConstructor) {
    ShoppingList sl("Animali");
    ASSERT_EQ(sl.getShoppingListName(),"Animali");
}


TEST_F(ShoppingListSuite, TestAddItem) {
    Item carne("carne","cibo",4);
    s.addItem(carne);
    int size=s.getShoppingList().size();
    ASSERT_EQ(size,4);    //item nella lista

    ASSERT_EQ(s.getNotBoughtCount(),11); //oggetti da comprare in totale

    Item carne2("carne","cibo",2);    //provo ad aggiungere un oggetto con lo stesso nome(deve cambiare solo il numero tot di oggetti)
    s.addItem(carne2);
    size=s.getShoppingList().size();
    ASSERT_EQ(size,4);
    ASSERT_EQ(s.getNotBoughtCount(),13);

    auto itr= s.getShoppingList().find("pane");
    itr->second->setItemQta(2);
    auto ris= itr->second->getItemQta();
    ASSERT_EQ(size,4);
    ASSERT_EQ(ris,2);
}



TEST_F(ShoppingListSuite, TestRemoveItem) {
    s.removeItem("ciliegia");
    int size=s.getShoppingList().size();
    ASSERT_EQ(size,2);
    ASSERT_EQ(s.getNotBoughtCount(),6);
}


TEST_F(ShoppingListSuite, TestSetBought) {
    s.setBought("ciliegia");
    ASSERT_EQ(s.getNotBoughtCount(),6);
}


TEST_F(ShoppingListSuite,TestSubject)
{
    s.attach(&user);
    ASSERT_EQ(1,s.getObservers().size());

    s.detach(&user);
    ASSERT_EQ(0,s.getObservers().size());
}


TEST_F(ShoppingListSuite, TestNotBought) {
    ASSERT_EQ(7,s.getNotBoughtCount());
}


TEST_F(ShoppingListSuite, GettersAndSetters)
{
    s.setShoppingListName("lavoro");
    ASSERT_EQ("lavoro",s.getShoppingListName());
}