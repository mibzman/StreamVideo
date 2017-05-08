/*
  Account_t.cpp

  Test program for class Account
*/

#include <iostream>
#include <cassert>
#include <string>

#include "Account.hpp"
#include "Stream.hpp"
#include "Video.hpp"

int main() {

    // no streaming
    {
        Account customer("Fred");

        assert(customer.getName() == "Fred");

        // test using literal string
        assert(customer.data() == "");
    }

    // TODO: Add test cases

    //Test case for Issue 8: Test method for account data
    {
	Account customer("Joe");

	Video testVideo("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 0);

	Stream testStream(testVideo, 1);

	customer.addStream(testStream);

	assert(customer.data() == "Joe,MOVIE,The Lord of the Rings: The Fellowship of the Ring,3,18,3\n");
    }

    //Additional test cases...
   //test the Account report
   {
Account customer("Larry");

Video testVideo("Bolt", 0, 1, 37, 0);


   }



    return 0;
}
