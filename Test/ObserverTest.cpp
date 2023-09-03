//
// Created by Ivan on 07/08/2023.
//

#include "gtest/gtest.h"
#include "../Observer.h"
#include "../ShoppingList.h"

// Definisci una classe di test chiamata ObserverTest, derivata da testing::Test e da Observer
class ObserverTest : public testing::Test, public Observer {
public:
    // Metodo di callback implementato da Observer
    // lo sovrascrivo per tenere traccia degli aggiornamenti
    void update(const string& listName) override {
        updated = true;
    }

    // Metodo per verificare se l'aggiornamento è avvenuto
    bool isUpdated() const {
        return updated;
    }

protected:
    // Metodo SetUp eseguito prima di ogni test
    void SetUp() override {
        s.attach(this); // Aggiungi l'observer (this) alla shopping list (s)
    }

    // Metodo TearDown eseguito dopo ogni test
    void TearDown() override {
        s.detach(this); // Rimuovi l'observer (this) dalla shopping list (s)
    }

    bool updated = false; // Flag per tenere traccia degli aggiornamenti
    ShoppingList s {"palestra"}; // Crea una shopping list di nome "palestra"
    Item manubrio {"manubrio", "attrezzatura", 3}; // Crea un oggetto Item di nome "manubrio" con categoria "attrezzatura" e quantità 3
};

// Definisci il test per verificare la notifica dell'aggiunta di un elemento alla shopping list
TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated()); // Verifica che l'update iniziale sia falso

    s.addItem(manubrio); // Aggiungi l'oggetto manubrio alla shopping list
    ASSERT_TRUE(isUpdated()); // Verifica che l'update sia diventato vero dopo l'aggiunta dell'oggetto
}

