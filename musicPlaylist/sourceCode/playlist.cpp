#include<iostream>
#include<string>
#include<vector>
#include "playlist.h"

Playlist::Playlist(std::string name){
    this->name = name;
}
std::string Playlist::getName(){
    return this->name;
}
void Playlist::addSong(Song s){
    songs.push_back(s);
}

void Playlist::removeSong(int songNumber){
    songs.erase(songs.begin()+songNumber);
}

void Playlist::changeOrderOfSongsInPlaylist(int currentMusicIndex, int desiredMusicIndex){

    if(currentMusicIndex>desiredMusicIndex){
        Song targetedSong=songs.at(currentMusicIndex-1);
        songs.insert(songs.begin()+desiredMusicIndex-1,targetedSong);
        songs.erase((songs.begin()+currentMusicIndex));
    }
    else if(desiredMusicIndex>currentMusicIndex){
        Song targetedSong=songs.at(currentMusicIndex-1);
        songs.erase((songs.begin()+currentMusicIndex-1));
        songs.insert(songs.begin() + desiredMusicIndex-1, targetedSong);
    }
}

void Playlist::playPreviousSong(){
    if (currentSongIndex > 0){
        currentSongIndex=currentSongIndex-1;
        playSong(currentSongIndex);
    }
    else{
        std::cout<<"This is the first song in the playlist."<<std::endl;
    }
}

void Playlist::playNextSong(){
    if (currentSongIndex < songs.size() - 1){
        currentSongIndex = currentSongIndex + 1;
        playSong(currentSongIndex);
    }
    else{
        std::cout<<"This is the last song in the playlist."<<std::endl;
    }
}

int Playlist::getNumberOfSongs(){
    return songs.size();
}

void Playlist::showAllSongs(){
    if(songs.size()==0){
        std::cout<<"You playlist has no songs."<<std::endl;
        return;
    }
    else{
        std::cout<<"Songs in playlist:"<<std::endl;
        for (int index = 0; index < songs.size(); index++){
            std::cout<<index + 1<<". "<<songs.at(index).getName()<<std::endl;
        }
    }
}

void Playlist::playSong(int songNumber){
    std::cout<<songs.at(songNumber).getName()<<" is playing"<<std::endl;
    currentSongIndex=songNumber;
    isSongPlaying = true;
    while(true){
        std::cout<<"Please select an option:"<<std::endl;
        if(isSongPlaying==true){
            std::cout<<"1. Pause"<<std::endl;
        }
        else{
            std::cout<<"1. Resume"<<std::endl;
        }
        std::cout<<"2. Previous song"<<std::endl;
        std::cout<<"3. Next song"<<std::endl;
        std::cout<<"4. Back to main menu"<<std::endl;
        int option;
        option = takeUserInput();
        switch(option){
                case 1:
                    if(isSongPlaying==true){
                        pauseSong();
                    }
                    else{
                        playSong(currentSongIndex);
                    }
                    break;
                case 2:
                    playPreviousSong();
                    break;
                case 3:
                    playNextSong();
                    break;
                case 4:
                    return;
                    break;
                default:
                    std::cout<<"Invalid option. Please try again."<<std::endl;
                    break;
        }
    }
}

void Playlist::pauseSong(){
    isSongPlaying = false;
    std::cout<<songs.at(currentSongIndex).getName()<<" is paused "<<std::endl;
}
