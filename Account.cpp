/*
  Account.cpp

  Definition file for Account class
*/

#include "Account.hpp"
#include "Video.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Account::Account(const std::string& name)
    : name(name)
{ }

// account name
std::string Account::getName() const {

    return name;
}

// add a stream to this account
void Account::addStream(const Stream& stream) {

    streams.push_back(stream);
}

// account streaming report
std::string Account::report() const {

    // stringstream to convert data
    std::ostringstream output;

    // customer name
    output << "Stream Report for Account: " << getName() << '\n';

    // list of streams
    output << "Streams:" << '\n';
    int totalStreams = 0;
    int totalOriginals = 0;
    int totalHours = 0;
    int totalMinutes = 0;
    for (std::vector<Stream>::const_iterator it = streams.begin(); it != streams.end(); ++it) {
    	//displays the report for an instance in the vector of streams
        displayReport(it, output, totalStreams, totalOriginals, totalHours, totalMinutes);
    }
    output << '\n';

    /*// total stream counts
    output << "Total Stream Events: " << totalStreams << '\n';

    // total non-original stream counts
    output << "Non-Original Stream Events: " << (totalStreams - totalOriginals) << '\n';

    // total time
    int minutes = totalMinutes % 60;
    int hours = totalHours + totalMinutes / 60;
    output << "Total Time: " << hours << ":" << minutes << '\n';*/

    //displays the total amounts for the report of the account
    displayTotals(output, totalStreams, totalOriginals, totalHours, totalMinutes);

    return output.str();
}

// account data in CSV
std::string Account::data() const {

    // stringstream to convert data
    std::ostringstream output;

    // customer name
    std::string name = getName();

    // list of streams
    for (std::vector<Stream>::const_iterator it = streams.begin(); it != streams.end(); ++it) {
    	//displays the data at a given instance in the vector
        displayData(it, output);
    }

    return output.str();
}

//determines the type of the account and determines the stream count
void Account::determineCount(std::vector<Stream>::const_iterator it, int &originals, int &streamCount) const
{
	switch(it->getVideo().getType()) {

            // for movies, the stream count is the number of hours, with a minimum of 1
            case Video::MOVIE:
            streamCount += it->getOccurrences() * (it->getVideo().getHours() ? it->getVideo().getHours() : 1);
            break;

            // for TV shows, the stream count is just the number of streams
            case Video::TVSHOW:
            streamCount += it->getOccurrences();
            break;

            // for TV shows, the stream count is just the number of streams
            case Video::ORIGINAL:
            originals += it->getOccurrences();
            streamCount += it->getOccurrences();
            break;
        }
}

//determines the type of the account and outputs the info based on the type
void Account::determineOutput(std::vector<Stream>::const_iterator it, std::ostringstream &output) const
{
	// stream type
        switch(it->getVideo().getType()) {

            // for movies, the stream count is the number of hours, with a minimum of 1
            case Video::MOVIE:
            output << "MOVIE";
            break;

            // for TV shows, the stream count is just the number of streams
            case Video::TVSHOW:
            output << "TVSHOW";
            break;

            // for TV shows, the stream count is just the number of streams
            case Video::ORIGINAL:
            output << "ORIGINAL";
            break;
        }    
}

//determines the type of the account and displays the stream count that corresponds to that type
void Account::displayCount(std::vector<Stream>::const_iterator it, std::ostringstream &output) const
{
	switch(it->getVideo().getType()) {

            // for movies, the stream count is the number of hours, with a minimum of 1
            case Video::MOVIE:
            output << (it->getOccurrences() * (it->getVideo().getHours() ? it->getVideo().getHours() : 1));
            break;

            // all others are just the number of occurrences
            default:
            output << it->getOccurrences();
            break;
        }
}

//displays the output for the report at a certain instance
    void Account::displayReport(std::vector<Stream>::const_iterator it, std::ostringstream &output, int &totalStreams, int &totalOriginals, int &totalHours, int &totalMinutes) const
    {
    	// title of stream
        output << '\t' << it->getVideo().getTitle();

        // current total hours and minutes
        totalHours += it->getVideo().getHours() * it->getOccurrences();
        totalMinutes += it->getVideo().getMinutes() * it->getOccurrences();

        // stream counts and originals
        int streamCount = 0;
        int originals = 0;
        determineCount(it, originals, streamCount);

        // stream counts for this video
        std::ostringstream out_str_stream;
        output << '\t' << streamCount << '\n';

        totalStreams += streamCount;
        totalOriginals += originals;
    }

     //displays the output for the data at a certain instance
    void Account::displayData(std::vector<Stream>::const_iterator it, std::ostringstream &output) const
    {
    	// customer name
    	output << name << ',';

    	//determines the output by the stream type
    	determineOutput(it, output);

        // stream title
        output << ',' << it->getVideo().getTitle();

        // stream hours and minutes
        output << ',' << (it->getVideo().getHours() * it->getOccurrences());
        output << ',' << (it->getVideo().getMinutes() * it->getOccurrences());

        // stream counts
        output << ',';
        displayCount(it, output);

        output << '\n';
    }

        //displays the total amounts for the report
    void Account::displayTotals(std::ostringstream &output, int &totalStreams, int &totalOriginals, int &totalHours, int &totalMinutes) const
    {
    	// total stream counts
    	output << "Total Stream Events: " << totalStreams << '\n';

   		// total non-original stream counts
   	 	output << "Non-Original Stream Events: " << (totalStreams - totalOriginals) << '\n';

    	// total time
    	int minutes = totalMinutes % 60;
    	int hours = totalHours + totalMinutes / 60;
    	output << "Total Time: " << hours << ":" << minutes << '\n';
    }