//
// Created by Ivan on 07/08/2023.
//

#include "gtest/gtest.h"
#include "../Observer.h"
#include "../ShoppingList.h"


class ObserverTest : public testing::Test, public Observer {
public:
    void update(const string& listName) override {
        updated = true;
    }

    bool isUpdated() const {
        return updated;
    }

protected:

    void SetUp() override {
        s.attach(this);

    }

    void TearDown() override {
        s.detach(this);
    }

    bool updated = false;
    ShoppingList s {"Casa"};
    Item carta {"carta","bagno",3};

};


TEST_F(ObserverTest, Update) {
    ASSERT_FALSE(isUpdated());

    s.addItem(carta);
    ASSERT_TRUE(isUpdated());
}
