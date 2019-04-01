//
// Created by kyle on 26/03/19.
//

#ifndef GOOGLETEST_1_INTRO_MOCKING_HPP
#define GOOGLETEST_1_INTRO_MOCKING_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <vector>


//Note: This is what we are mocking
//Only an abstract class for this demonstration. Pretend functions are implemented...
class DatabaseAccess{
public:
    //Bools indicate successful connection etc. In this case, logout is void, as this would only make local changes.
    virtual bool login(std::string username, std::string password) = 0;
    virtual void logout() = 0;
    virtual bool updatePassword(std::string username, std::string password, std::string salt) = 0;
    virtual bool updateUsername(std::string username, std::string password) = 0;
};


//Note: Now, using the mock class, we dont even need to access the database. This is only useful if what we are testing depends on the mocked object
//Note: (but we aren't actually testing the mocked object). This means we can save time (as we dont need to send web requests). We can also test under
//Note: specific behaviours, such as hard to replicate bugs.
class MockDatabaseAccess : public DatabaseAccess {
public:
    MOCK_METHOD2(login, bool(std::string, std::string));
    MOCK_METHOD0(logout, void());
    MOCK_METHOD3(updatePassword, bool(std::string, std::string, std::string));
    MOCK_METHOD2(updateUsername, bool(std::string, std::string));
};





//Note: This is what we are actually testing
class Database {
    std::vector<std::string> accountInfo;
public:
    //This is the specific function we will test
    std::vector<std::string> getAccountInfo(DatabaseAccess &databaseAccess, const std::string &username, const std::string &password) {
        if (databaseAccess.login(username, password)) {
            accountInfo.emplace_back("Some random info I am pretending I parsed via communicating with the server");
            accountInfo.emplace_back("More random info");
        } else {
            std::cerr << "Either could not connect to DB or incorrect username/password combo given..." << std::endl;
        }

        return accountInfo;
    }
    //Pretend this class is more complete...
};


#endif //GOOGLETEST_1_INTRO_MOCKING_HPP
