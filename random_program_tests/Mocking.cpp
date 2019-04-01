//
// Created by kyle on 26/03/19.
//

#include "Mocking.hpp"

using testing::_;
using testing::A;
using testing::Return;

TEST(DatabaseTests, getAccountInfo_GetsMeaningfulDataWhenTrue){
    MockDatabaseAccess mdbAccess;
    Database database;

    //Underscore (matcher) in login means we expect args to be inputted, but what those args actually are do not matter
    //We could have written login("SomeUser", "SomePassword")... however, this is unnecessary in this case.
    //Overspecification causes the test to become all too rigid, and complicates the tests intention
    EXPECT_CALL(mdbAccess, login(_,_))
        .Times(1)
        .WillOnce(Return(true));

    //Use derived mock class instead of implementation (using polymorphism)
    std::vector accountInfo = database.getAccountInfo(mdbAccess, "SomeUser", "SomePassword");

    ASSERT_NE(0, accountInfo.size()) << "No account info has been gathered!";

    EXPECT_EQ(2, accountInfo.size());
    EXPECT_EQ("Some random info I am pretending I parsed via communicating with the server", accountInfo[0]);
    EXPECT_EQ("More random info", accountInfo.back());
}


TEST(DatabaseTests, getAccountInfo_HasNoDataWhenFalse){
    MockDatabaseAccess mdbAccess;
    Database database;

    //_ is a matcher. So is A<type>(). A<type>() means any value that matches the specified type can be passed (useful for overloaded functions)
    EXPECT_CALL(mdbAccess, login(A<std::string>(), A<std::string>()))
            .Times(testing::Exactly(1))
            .WillOnce(Return(false));

    //Use derived mock class instead of implementation (using polymorphism)
    std::vector accountInfo = database.getAccountInfo(mdbAccess, "SomeUser", "SomePassword");

    ASSERT_EQ(0, accountInfo.size()) << "Account info gathered despite incorrect details!";
}