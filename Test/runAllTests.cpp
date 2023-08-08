//
// Created by Ivan on 07/08/2023.
//

#include "gtest/gtest.h"

int main(int argc, char ** argv)
{
    // Inizializza Google Test con gli argomenti della riga di comando
    ::testing::InitGoogleTest(&argc, argv);
    // Esegui tutti i test registrati
    return RUN_ALL_TESTS();
}