/*
  Account.hpp

  Include file for Account class
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Stream.hpp"

#include <string>
#include <vector>

class Account {
public:

    // constructor
    Account(const std::string& call);

    // account name
    std::string getName() const;

    // add a new stream
    void addStream(const Stream& watch);

    // account streaming report
    std::string report() const;

    // account data in CSV
	std::string data() const;

private:
    std::string name;
    std::vector<Stream> streams;
};

#endif
