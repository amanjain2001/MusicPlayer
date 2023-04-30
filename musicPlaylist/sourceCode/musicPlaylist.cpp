#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "musicLibrary.h"
#include "musicPlaylist.h"

std::string MusicPlaylist::getPlaylistNameFromUser(){
    std::string playlistName;
    std::cout<<"Please enter playlist name: "<<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, playlistName);
    return playlistName;
}

void MusicPlaylist::createPlaylist(std::vector<Playlist>& playlists){
    std::string playlistName = getPlaylistNameFromUser();
    playlists.push_back(Playlist(playlistName));
    std::cout<<playlistName<<" created successfully."<<std::endl;
}

void MusicPlaylist::addSongToPlaylist(std::vector<Playlist>& playlists){
    std::string playlistName = getPlaylistNameFromUser();
    bool isPlaylistExist = false;
    for(int i = 0; i < playlists.size(); i++){
        if(playlists.at(i).getName() == playlistName){
            isPlaylistExist = true;
            std::cout<<"Enter song name: ";
            std::string songName;
            MusicLibrary musicLibrary;
            std::getline(std::cin, songName);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::vector<std::string> globalSongs = musicLibrary.getLibrarySongs();
            bool isSongExistInGlobalLibrary;
            int musicLibrarySongsCount = globalSongs.size();
            for(int i=0;i<musicLibrarySongsCount;i++){
                if(globalSongs.at(i)==songName){
                    isSongExistInGlobalLibrary = true;
                    break;
                }
                else{
                    isSongExistInGlobalLibrary=false;
                }
            }
            if(!isSongExistInGlobalLibrary){
                std::cout<<"You can't add this song in the playlist, as this song don't exist in your file"<<std::endl;
                return;
            }
            playlists.at(i).addSong(Song(songName));
            std::cout<<songName<<" has been added to "<<playlistName<<" successfully."<<std::endl;
            break;
        }
    }
    if(!isPlaylistExist){
        std::cout<<playlistName<<" does not exist."<<std::endl;
    }
}

void MusicPlaylist::removeSongFromPlaylist(std::vector<Playlist>& playlists){
    std::string playlistName = getPlaylistNameFromUser();
    bool isPlaylistExist = false;
    for(int playlistIndex = 0; playlistIndex < playlists.size(); playlistIndex++){
        if(playlists.at(playlistIndex).getName() == playlistName){
            isPlaylistExist = true;
            playlists.at(playlistIndex).showAllSongs();
            std::cout<<"Enter which song number do you want to remove: ";
            int songIndex;
            songIndex = takeUserInput();
            if(songIndex > 0 && songIndex <= playlists.at(playlistIndex).getNumberOfSongs()){
                playlists.at(playlistIndex).removeSong(songIndex - 1);
                std::cout<<"Song removed from playlist \""<<playlistName<<"\"."<<std::endl;
            } 
            else{
                std::cout<<"Invalid song number. Please try again."<<std::endl;
            }
            break;
        }
    }
    if(!isPlaylistExist){
        std::cout<<playlistName<<" does not exist."<<std::endl;
    }
}

void MusicPlaylist::changeOrderOfSongsInPlaylist(std::vector<Playlist>& playlists){
    std::string playlistName = getPlaylistNameFromUser();
    bool isPlaylistExist = false;
    for(int i = 0; i < playlists.size(); i++){
        if(playlists.at(i).getName() == playlistName){
            isPlaylistExist = true;
            playlists.at(i).showAllSongs();
            int currentMusicIndex, desiredMusicIndex;
            std::cout<<"Enter which numberth song do you want to move up down"<<std::endl;
            currentMusicIndex = takeUserInput();
            if(currentMusicIndex > 0 && currentMusicIndex <= playlists.at(i).getNumberOfSongs()){
                std::cout<<"Enter at what position do you want to set the song "<<std::endl;
                desiredMusicIndex = takeUserInput();
                if(desiredMusicIndex > 0 && desiredMusicIndex <= playlists.at(i).getNumberOfSongs()){
                    playlists.at(i).changeOrderOfSongsInPlaylist(currentMusicIndex, desiredMusicIndex);
                    std::cout<<"Your updated playlist:"<<std::endl;
                    playlists.at(i).showAllSongs();
                    break;
                }
                else{
                    std::cout<<"Invalid song number. Please try again."<<std::endl;
                }
            }
            else{
                std::cout<<"Invalid song number. Please try again."<<std::endl;
            }            
        }
    }
    if(!isPlaylistExist){
        std::cout<<playlistName<<" does not exist."<<std::endl;
    }
}

void MusicPlaylist::playSong(std::vector<Playlist>& playlists){
    std::string playlistName = getPlaylistNameFromUser();
    bool isPlaylistExist = false;
    for(int i = 0; i < playlists.size(); i++){
        if(playlists.at(i).getName() == playlistName){
            isPlaylistExist = true;
            playlists.at(i).showAllSongs();
            std::cout<<"Enter which numberth song do you want to play: ";
            int songIndex;
            songIndex = takeUserInput();
            if(songIndex > 0 && songIndex <= playlists.at(i).getNumberOfSongs()){
                playlists.at(i).playSong(songIndex - 1);
            }
            else{
                std::cout<<"Invalid song number. Please try again."<<std::endl;
            }
            break;
        }
    }
    if(!isPlaylistExist){
        std::cout<<playlistName<<" does not exist."<<std::endl;
    }
}

void MusicPlaylist::showSongs(std::vector<Playlist>& playlists){
    std::string playlistName = getPlaylistNameFromUser();
    bool isPlaylistExist = false;
    for(int i = 0; i < playlists.size(); i++){
        if(playlists.at(i).getName() == playlistName){
            isPlaylistExist = true;
            playlists.at(i).showAllSongs();
            break;
        }
    }
    if(!isPlaylistExist){
        std::cout<<playlistName<<" does not exist."<<std::endl;
    }
}

void MusicPlaylist::showAllPlaylists(std::vector<Playlist>& playlists){
    if(playlists.size()==0){
        std::cout<<"Your playlist is empty"<<std::endl;
        return;
    }
    else{
        std::cout<<"Your playlists are: "<<std::endl;
        for(int i=0;i<playlists.size();i++){
            std::cout<<playlists.at(i).getName()<<std::endl;
        }
    }
}