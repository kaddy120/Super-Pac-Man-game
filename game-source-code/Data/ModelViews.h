#pragma once
#include <string>
#include "../Logic/Vector2.h"
#include "../Logic/Definitions.h"

using std::string;
/**
 *@class TextModelView
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This class is responsible for modelling the text models for Render class.
 \version 3.0
*/

class TextModelView
{
public:

    string Level;
    string Lives;
    string HighestScore;
    string CurrentScore;
    int highscore_;
    int currentscore;
};
/**
 *@class  StaticEntitesViewModel
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This class is resposnsible for all the none moving entities on the maze
 \version 3.0
*/

class StaticEntitesViewModel
{
public:

     /**
    * @brief an std variabe is resonsible for all the tile
    */
    std::string Title;
       /**
    * @brief an Position of type vector2
    */
    Vector2 Positon;
    /**
    * @brief an Dimention of type vector2
    */
    Vector2 Dimention;
};
/**
 *@class  GhostModelView
 *@author Dembe Munyai and Kaddy Marindi
 *@brief The function is responsible for checking the mode of the ghost.It inherits from the StaticEntitesViewModel class
 \version 3.0
*/

class GhostModelView : public StaticEntitesViewModel
{
public:
        /**
    * @brief a Mode of type mode
    */
    Mode Mode;
};

/**
 *@class  PacManViewModel
 *@author Dembe Munyai and Kaddy Marindi
 *@brief The function is responsible for modelling a Pacman with its directions and state for rendering.It inherits from the StaticEntitesViewModel class
 \version 3.0
*/
class PacManViewModel : public StaticEntitesViewModel
{
public:

     /**
    * @brief returns a function of type Direction

    *  @return returns a Direction of type Direction
    */

    Direction Direction;
      /**
    * @brief returns a State of type State
    */

    State State;
};
