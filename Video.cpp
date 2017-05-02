/*
  Video.cpp

  Definition file for Video class
*/

#include "Video.hpp"

// constructor
Video::Video(const std::string& titleCall, int movType, int numHours, int numMinutes, int episodeNum)
    : title(titleCall), type(movType), hours(numHours), minutes(numMinutes), episodes(episodeNum)
{ }

// video title
const std::string& Video::getTitle() const {

    return title;
}

// video type
int Video::getType() const {

    return type;
}

// video length in hours
int Video::getHours() const {

    return hours;
}

// video length in minutes
int Video::getMinutes() const {

    return minutes;
}

// number of episodes
int Video::getEpisodes() const {

	// special case as movies do not have episodes
	if (type == Video::MOVIE)
		return 0;

    return episodes;
}

// set video length
void Video::setLength(int timeHours, int timeMinutes) {

	this->hours = timeHours;
	this->minutes = timeMinutes;
}
