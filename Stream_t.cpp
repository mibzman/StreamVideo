/*
  Stream_t.cpp
thomas
  Test program for class Stream
*/

#include <cassert>

#include "Stream.hpp"

bool videosAreEqual(Video video1, Video video2){
    return
        video1.getTitle() == video2.getTitle() &&
        video1.getType() == video2.getType() &&
        video1.getHours() == video2.getHours() &&
        video1.getMinutes() == video2.getMinutes() &&
        video1.getEpisodes() == video2.getEpisodes();
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
