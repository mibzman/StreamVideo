/*
  Video_t.cpp
  Test program for class Video
*/

#include <cassert>
#include <iostream>
#include <string>

#include "Video.hpp"

int main() {
  // TODO: Add test cases
  //test case 1
  //test the basic constructor
  {
    Video StarWars ("A new Hope",5,2,35,0 );
  }
  {
    Video StarWars ("A new Hope",5,2,35,0 );
    //now test the getTitle
    assert(StarWars.getTitle()=="A new Hope");
  }
  {
    Video StarWars ("A new Hope",5,2,35,0 );
    //now test the getType
    assert(StarWars.getType()==5);
  }
  {
    Video StarWars ("A new Hope",5,2,35,0 );
    //now test the getHours
    assert(StarWars.getHours()==2);
  }
  {
    Video StarWars ("A new Hope",5,2,35,0 );
    //now test the getMinutes
    assert(StarWars.getMinutes()==35);
  }
  {
    Video StarWars ("A new Hope",5,2,35,0 );
    //now test the getEpisodes
    assert(StarWars.getEpisodes()==0);
  }
  {
    Video StarWars ("A new Hope",5,2,35,0 );
    //now test the getEpisodes
    StarWars.setLength(2,35);
  }
  return 0;
}
