/*
  Stream_t.cpp
thomas
  Test program for class Stream
*/

#include <cassert>

#include "Stream.hpp"

bool videosAreEqual(Video video1, Video video2){
	return
		video1.getTitle() == video1.getTitle() ||
		video1.getType() == video1.getType() ||
		video1.getHours() == video1.getHours() ||
		video1.getMinutes() == video1.getMinutes() ||
		video1.getEpisodes() == video1.getEpisodes();
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
    	assert(videosAreEqual(video, outputVideo));
    }
    

    return 0;
}
