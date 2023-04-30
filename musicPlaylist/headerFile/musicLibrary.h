#include<vector>
#include<string>
#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

class MusicLibrary{
private:
    std::vector<std::string> librarySongs;
public:
    void createSongsLibrary();
    std::vector<std::string> getLibrarySongs();
};

#endif