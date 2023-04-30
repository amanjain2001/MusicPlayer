#include<gtest/gtest.h>
#include"song.h"

TEST(SongTest, getName){
    std::string title = "Tere Haan";
    Song song(title);
    EXPECT_EQ(song.getName(), "Tere Haan");
}