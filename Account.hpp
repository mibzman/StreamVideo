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
    Account(const std::string& name);

    // account name
    std::string getName() const;

    // add a new stream
    void addStream(const Stream& stream);

    // determine the type of an account
    void determineType(std::vector<Stream>::const_iterator it, int &originals, int &StreamCount) const;

    // account streaming report
    std::string report() const;

    // account data in CSV
	std::string data() const;

private:
    std::string name;
    std::vector<Stream> streams;
};

#endif
