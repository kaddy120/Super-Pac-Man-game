#include "FileReader.h"
#include <fstream>

FileReader::FileReader() : filePath_{"resources/file.txt"}
{
}

int FileReader::getHighestScore()
{
    scorefile_.open(filePath_, ios::in);
    scorefile_ >> highestscore;
    scorefile_.close();
    return highestscore;
}

void FileReader::setHighestScore(int gamescore)
{

    if(gamescore>=0)
    {
        highestscore = gamescore;
        scorefile_.open(filePath_, ios::out);
        scorefile_ << highestscore;
        scorefile_.close();
    }

}

FileReader::~FileReader()
{ }
