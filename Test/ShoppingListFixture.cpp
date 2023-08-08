//
// Created by Ivan on 07/08/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"


// Definisci una classe di test chiamata ShoppingListSuite, derivata da testing::Test
class ShoppingListSuite : public ::testing::Test {
protected:
    // Metodo SetUp eseguito prima di ogni test
    void SetUp() override {
        // Aggiungi alcuni elementi alla shopping list "palestra" prima di eseguire i test
        s.addItem(manubrio);
        s.addItem(polsini);
        s.addItem(cintura);
    }

    // Definisci gli oggetti che verranno utilizzati nei test
    ShoppingList s{"palestra"};
    Item manubrio{"manubrio", "attrezzatura", 1};
    Item polsini{"polsini", "accessori", 1};
    Item cintura{"cintura", "essenziali", 5};
    User user; // Utente utilizzato nei test
};

// Test per verificare il costruttore parametrizzato di ShoppingList
TEST_F(ShoppingListSuite, TestParametrizeConstructor) {
    ShoppingList sl("casa"); // Crea una shopping list "casa"
    ASSERT_EQ(sl.getShoppingListName(), "casa"); // Verifica che il nome della shopping list sia "casa"
}

// Test per verificare l'aggiunta di un elemento alla shopping list
TEST_F(ShoppingListSuite, TestAddItem) {
    Item catena("catena", "essenziali", 4);
    s.addItem(catena); // Aggiungi l'oggetto "catena" alla shopping list
    int size = s.getShoppingList().size();

    // Verifica che la dimensione della shopping list sia 4
    ASSERT_EQ(size, 4);

    // Verifica che il numero totale di oggetti non comprati sia 11
    ASSERT_EQ(s.getNotBoughtCount(), 11);

    // Provo ad aggiungere un oggetto con lo stesso nome (deve cambiare solo il numero totale di oggetti)
    Item catenaPro("catena", "essenziali", 2);
    s.addItem(catenaPro);
    size = s.getShoppingList().size();
    ASSERT_EQ(size, 4);
    ASSERT_EQ(s.getNotBoughtCount(), 13);

    // Modifica la quantità dell'oggetto "cintura" e verifica che sia cambiata correttamente
    auto itr = s.getShoppingList().find("cintura");
    itr->second->setItemQta(2);
    auto ris = itr->second->getItemQta();
    ASSERT_EQ(size, 4);
    ASSERT_EQ(ris, 2);
}

// Test per verificare la rimozione di un elemento dalla shopping list
TEST_F(ShoppingListSuite, TestRemoveItem) {
    s.removeItem("manubrio"); // Rimuovi l'oggetto "manubrio" dalla shopping list
    int size = s.getShoppingList().size();
    ASSERT_EQ(size, 2); // Verifica che la dimensione della shopping list sia 2
    ASSERT_EQ(s.getNotBoughtCount(), 6); // Verifica che il numero totale di oggetti non comprati sia 6
}

// Test per verificare il setBought di un elemento della shopping list
TEST_F(ShoppingListSuite, TestSetBought) {
    s.setBought("manubrio"); // Imposta l'oggetto "manubrio" come comprato
    ASSERT_EQ(s.getNotBoughtCount(), 6); // Verifica che il numero totale di oggetti non comprati sia 6
}

// Test per verificare il funzionamento del subject-observer pattern
TEST_F(ShoppingListSuite, TestSubject) {
    s.attach(&user); // Aggiungi l'utente come observer della shopping list
    ASSERT_EQ(1, s.getObservers().size()); // Verifica che l'utente sia stato aggiunto correttamente come observer

    s.detach(&user); // Rimuovi l'utente come observer della shopping list
    ASSERT_EQ(0, s.getObservers().size()); // Verifica che l'utente sia stato rimosso correttamente come observer
}

// Test per verificare il conteggio degli oggetti non comprati
TEST_F(ShoppingListSuite, TestNotBought) {
    ASSERT_EQ(7, s.getNotBoughtCount()); // Verifica che il conteggio degli oggetti non comprati sia 7
}

// Test per verificare i metodi getter e setter della shopping list
TEST_F(ShoppingListSuite, GettersAndSetters) {
    s.setShoppingListName("ufficio"); // Imposta il nome della shopping list a "ufficio"
    ASSERT_EQ("ufficio", s.getShoppingListName()); // Verifica che il nome della shopping list sia "ufficio"
}
