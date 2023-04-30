#include<iostream>
#include<string>
#include<vector>
#include"song.h"
#include"inputValidator.h" 
#ifndef PLAYLIST_H
#define PLAYLIST_H

class Playlist{
private:
    std::string name;
    std::vector<Song> songs;
    int currentSongIndex;
    bool isSongPlaying;
public:
    Playlist(std::string name);
    std::string getName();
    void addSong(Song s);
    void removeSong(int songNumber);
    void changeOrderOfSongsInPlaylist(int currentMusicIndex, int desiredMusicIndex);
    void playPreviousSong();
    void playNextSong();
    void showAllSongs();
    void playSong(int songNumber);
    void pauseSong();
    int getNumberOfSongs();
};
#endif