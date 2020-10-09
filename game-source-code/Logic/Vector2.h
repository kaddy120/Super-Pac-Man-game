#ifndef VECTOR2_H
#define VECTOR2_H

/**
 *@class Vector2
 *@author Dembe Munyai and Kaddy Marindi
 *@brief data object that hold pair value of x and y. x and y can either be dimensions or coordinates
 \version 3.0
*/
class Vector2
{
public:
    	  /**
    * @brief Vector2 parameterless constructor
    */
    Vector2(): X(0), Y(0) {}
    	  /**
    * @brief Vector2 constructor.
    * @param x is of type float. X is mostly x-coordinate but can be anything
    * @param y is of type float. Y is mostly x-coordinate but can be anything
    */

    Vector2(const float& x, const float& y) : X(x), Y(y) {}
       	  /**
    * @brief Vector2 is copy constructor.
    * @param other is of type Vector2. Is an object of tpe Vector2
    */
    Vector2(const Vector2& other) : X(other.X), Y(other.Y){}
    	  /**
    * @brief an overload operator of ===
 * @param other is of type Vector2. Is an object of tpe Vector2
 * @return return true if this object == other
    */

    bool operator == (const Vector2& other) const
    {
        if (X == other.X && Y == other.Y) return true;
        return false;
    }
    /**
    * @brief GetPosition function is a virtua funtion that return a position
    * @return a position of type Vector2
    */
    Vector2& add(const Vector2& other)
    {
       this->X += other.X;
       this->Y += other.Y;
       return *this;
    }

    /**
    * @brief subtract is a function to subtract two Vector2 objects
    * @param other is of type Vector2. Is an object of tpe Vector2
    * @return return an an output of subtraction of type Vector2
    */

    Vector2& subtract(const Vector2& other)
    {
        this->X -= other.X;
        this->Y -= other.Y;
        return *this;
    }
    /**
    * @brief X is of type float.
    * @return float
    */
    float X;
    	  /**
    * @brief Y is of type flaot
    * @return float.
    */
    float Y;
};

#endif
