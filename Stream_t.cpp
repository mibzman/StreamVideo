/*
  Stream_t.cpp
thomas
  Test program for class Stream
*/

#include <cassert>

#include "Stream.hpp"

bool operator==(const Video &video1, const Video &other) {
    return
        video1.getTitle() == other.getTitle() &&
        video1.getType() == other.getType() &&
        video1.getHours() == other.getHours() &&
        video1.getMinutes() == other.getMinutes() &&
        video1.getEpisodes() == other.getEpisodes();
}

int main() {

	//test getOccurrences
    {
    	Video video("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 0);
    	Stream stream(video, 1);

    	assert(stream.getOccurrences() == 1);
    }

    	//test getVideo
    {
    	Video video("The Lord of the Rings: The Fellowship of the Ring", 0, 3, 18, 0);
    	Stream stream(video, 1);

    	Video outputVideo = stream.getVideo();
    	assert(video == outputVideo);
    }
    

    return 0;
}
