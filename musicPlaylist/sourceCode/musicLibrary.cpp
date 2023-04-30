#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include "musicLibrary.h"

void MusicLibrary::createSongsLibrary(){
    std::ofstream songsLibraryFile;
    songsLibraryFile.open("songsLibrary.csv");
    char songName[100];
    bool userChoiceToAddSongs = true;
    while(userChoiceToAddSongs){
        std::cout<<"Enter the name of songs you want to add in library "<<std::endl;
        std::cin.ignore();
        std::cin.getline(songName, 100);
        songsLibraryFile<<songName<<", "<<"\n";
        std::cout<<"Do you want to add more songs in the library "<<std::endl<<"Press 1 for adding more songs, else press 0 "<<std::endl;
        std::cin>>userChoiceToAddSongs;
    }
    songsLibraryFile.close();
}

std::vector<std::string> MusicLibrary::getLibrarySongs(){
    std::ifstream songsLibraryFile("songsLibrary.csv");
    std::string line;
    while(std::getline(songsLibraryFile, line)){
        librarySongs.push_back(line);
    }
    songsLibraryFile.close();
    return librarySongs;
}