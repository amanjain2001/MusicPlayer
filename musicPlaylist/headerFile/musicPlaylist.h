#include <iostream>
#include <vector>
#include <string>
#include "playlist.h"

class MusicPlaylist{
private:
    std::string getPlaylistNameFromUser();
public:
    void createPlaylist(std::vector<Playlist>& playlists);
    void addSongToPlaylist(std::vector<Playlist>& playlists);
    void removeSongFromPlaylist(std::vector<Playlist>& playlists);
    void changeOrderOfSongsInPlaylist(std::vector<Playlist>& playlists);
    void playSong(std::vector<Playlist>& playlists);
    void showSongs(std::vector<Playlist>& playlists);
    void showAllPlaylists(std::vector<Playlist>& playlists);
};