//
// Created by Ivan on 07/08/2023.
//

#include "gtest/gtest.h"
#include"../Item.h"


TEST(ItemSuite,TestConstructor)
{
    Item i("pane","cibo",6);
    ASSERT_EQ(i.getItemQta(),6);
    ASSERT_EQ(i.getItemCategory(),"cibo");
    ASSERT_EQ(i.getItemName(),"pane");

    ASSERT_THROW(Item i2("pane","cibo",-2) ,out_of_range);
}


TEST(ItemSuite, TestSetItemquantity) {
    Item i("pane","cibo",3);
    ASSERT_THROW(i.setItemQta(-2),out_of_range);
}