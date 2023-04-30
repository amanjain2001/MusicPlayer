#include<gtest/gtest.h>
#include "playlist.h"

TEST(Playlist, getName){
    std::string playlistName = "My favorites";
    Playlist playlist(playlistName);
    EXPECT_EQ(playlist.getName(), "My favorites");
}

TEST(PlaylistTest, AddSong){
    std::string name = "My Playlist";
    Playlist playlist(name);
    std::string songTitle = "My Song";
    Song song(songTitle);
    playlist.addSong(song);
    EXPECT_EQ(playlist.getNumberOfSongs(), 1);
}

TEST(PlaylistTest, removeSong){
    std::string name = "My Playlist";
    Playlist playlist(name);
    std::string songTitle = "My Song";
    Song song(songTitle);
    playlist.addSong(song);
    EXPECT_EQ(playlist.getNumberOfSongs(), 1);
    playlist.removeSong(1);
    EXPECT_EQ(playlist.getNumberOfSongs(), 0);
}

TEST(PlaylistTest, getTotalsongs){
    std::string name = "My Playlist";
    Playlist playlist(name);
    EXPECT_EQ(playlist.getNumberOfSongs(), 0);
}