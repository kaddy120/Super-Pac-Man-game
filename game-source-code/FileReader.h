#pragma once
#include <string>
#include <fstream>

using std::string;
using std::ios;
using std::fstream;

class FileReader
{
    public:
        FileReader();
        int getHighestScore();
        void setHighestScore(int gamescore);

        ~FileReader();
private:
        fstream scorefile_;
        string filePath_;
        int highestscore;

};

