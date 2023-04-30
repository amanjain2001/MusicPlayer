#include<iostream>
#include<string>
#include"song.h"

Song::Song(std::string title){
    this->name=title;
}

std::string Song::getName(){
    return name;
}