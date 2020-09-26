#ifndef FileReader_H
#define FileReader_H
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
        int getLevel();


        ~FileReader();
private:
        fstream scorefile_;
        string filePath_;
        int highestscore;

};

#endif // FileReader_H