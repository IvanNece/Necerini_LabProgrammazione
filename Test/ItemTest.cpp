//
// Created by Ivan on 07/08/2023.
//

// Include la libreria Google Test per scrivere i test
#include "gtest/gtest.h"
#include"../Item.h"

// Inizia la suite di test per la classe Item
TEST(ItemSuite, TestConstructor) {
    // Crea un oggetto Item utilizzando il costruttore e specifico nome, categoria e quantità
    Item i("cavolfiore", "verdura", 5);

    // Verifica che i valori degli attributi dell'oggetto siano stati impostati correttamente
    ASSERT_EQ(i.getItemQta(), 5); // Verifica che la quantità sia 5
    ASSERT_EQ(i.getItemCategory(), "verdura"); // Verifica che la categoria sia "verdura"
    ASSERT_EQ(i.getItemName(), "cavolfiore"); // Verifica che il nome sia "cavolfiore"

    // Verifica che il costruttore lanci un'eccezione out_of_range se viene passata una quantità negativa
    ASSERT_THROW(Item i2("cavolfiore", "verdura", -3), out_of_range);
}

// Continua la suite di test per la classe Item
TEST(ItemSuite, TestSetItemquantity) {
    // Crea un oggetto Item utilizzando il costruttore
    Item i("cavolfiore", "verdura", 3);

    // Verifica che il metodo setItemQta lanci un'eccezione out_of_range se viene passata una quantità negativa
    ASSERT_THROW(i.setItemQta(-2), out_of_range);
}
