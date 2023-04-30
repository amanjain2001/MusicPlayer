#include <iostream>
#include <vector>
#include <string>
#include "playlist.h"
#include "musicPlaylist.h"

void showUserOptions(){
    std::cout<<"Please select an option:"<<std::endl;
    std::cout<<"1. Create a new playlist"<<std::endl;
    std::cout<<"2. Add a song to an existing playlist"<<std::endl;
    std::cout<<"3. Remove a song from an existing playlist"<<std::endl;
    std::cout<<"4. Change the order of songs in an existing playlist"<<std::endl;
    std::cout<<"5. Play a song from an existing playlist"<<std::endl;
    std::cout<<"6. Show songs of a playlist"<<std::endl;
    std::cout<<"7. Show all playlists"<<std::endl;
    std::cout<<"8. Exit"<<std::endl;
}

int main(){
    std::vector<Playlist> playlists;
    MusicPlaylist musicPlaylist;
    std::cout<<"Welcome to your music player."<<std::endl;
    while(true){
        showUserOptions();
        int option;
        option = takeUserInput();
        switch(option){
            case 1:
                musicPlaylist.createPlaylist(playlists);
                break;
            case 2:
                musicPlaylist.addSongToPlaylist(playlists);
                break;
            case 3:
                musicPlaylist.removeSongFromPlaylist(playlists);
                break;
            case 4:
                musicPlaylist.changeOrderOfSongsInPlaylist(playlists);
                break;
            case 5:
                musicPlaylist.playSong(playlists);
                break;
            case 6:
                musicPlaylist.showSongs(playlists);
                break;
            case 7:
                musicPlaylist.showAllPlaylists(playlists);
                break;
            case 8:
                std::cout<<"Thank you for using the music player."<<std::endl;
                return 0;
            default:
                std::cout<<"Invalid option. Please try again."<<std::endl;
                break;
        }
    }
}