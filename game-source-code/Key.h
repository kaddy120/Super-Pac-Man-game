#pragma once
#include "sprite.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>
#include "CircleSprite.h"
/**
* @class Key
* @brief The class assignes the keys to the maze
*The class also inherits from CircleSprite.
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/


class Key: public CircleSprite
{
public:

        /** \brief Default Constructor. Creates Key object.
        */
    Key();
        /** \brief Parameterized Constructor. Creates key object.
        *  \param radius of type float ,gives a radius dimension of the key entity.
        *\param Position is of type vector2.Sets the position of each key on the maze
        */

    Key(const float& radius, const Vector2& postion);
        /** \brief The function sets Key dimensions and gives them a position.This is done to ensure that.....
        *  \param radius of type float ,gives a radius dimension of the key entity.
        *   \param Position is of type vector2.Sets the position of each key on the maze
        */
    void SetKeyDimensions(const float& radius, const Vector2& postion);
    bool operator ==(const Key& other) const;

        /** \brief Function returns a unique key ID
         *\return string
         */
    std::string GetKeyId() const;

private:
    static unsigned int NumberOfKeys;
    std::string KeyId;
    std::string GenerateUniqueID();

};

