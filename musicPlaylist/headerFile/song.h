#include<iostream>
#include<string>
#ifndef SONG_H
#define SONG_H
class Song{
private:
    std::string name;
public: 
    Song(std::string title);
    std::string getName();
};
#endif