#pragma once
#include <string>
#include <fstream>

using std::string;
using std::ios;
using std::fstream;

/**
* @class FileReader
* @brief This class is responsible for reading reading the highest score
* from a file and to a file
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/

// exception class
//class FileCannotBeOpened{};

class FileReader
{
    public:
         /** \brief Default Constructor. Creates FileReader object.
         */
        FileReader();



          /** \brief Returns the high score from game.
         *  \return int
         */

        int getHighestScore();
         /** \brief Sets the high score of the game.
         *  \param gamescore is an integer(int).
         *  \return int
         */
        void setHighestScore(int gamescore);


        /** \brief Default Destructor. Destroys FileReader object.
          */
        ~FileReader();
private:
        fstream scorefile_;
        string filePath_;
        int highestscore;

};

