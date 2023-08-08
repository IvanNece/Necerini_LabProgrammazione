//
// Created by Ivan on 07/08/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

// Definisci una classe di test chiamata UserSuite, derivata da testing::Test
class UserSuite : public ::testing::Test {
protected:
    // Metodo SetUp eseguito prima di ogni test
    virtual void SetUp() {
        // Aggiungi alcune shopping list (s1, s2) all'utente (u) prima di eseguire i test
        u.addShoppingList(s1);
        u.addShoppingList(s2);
    }

    // Definisci le shopping list (s1, s2, s3) e l'utente (u) che verranno utilizzati nei test
    ShoppingList s1{"palestra"};
    ShoppingList s2{"casa"};
    ShoppingList s3{"ufficio"};
    User u;
};

// Test per verificare l'aggiunta di una shopping list all'utente
TEST_F(UserSuite, TestAddShoppingList) {
    u.addShoppingList(s3); // Aggiungi la shopping list "ufficio" all'utente
    ASSERT_EQ(3, u.getMyLists().size()); // Verifica che l'utente abbia ora 3 shopping list
}

// Test per verificare la rimozione di una shopping list dall'utente
TEST_F(UserSuite, TestRemoveShoppingList) {
    u.removeShoppingList("palestra"); // Rimuovi la shopping list "palestra" dall'utente
    ASSERT_EQ(1, u.getMyLists().size()); // Verifica che l'utente abbia ora 1 shopping list
}