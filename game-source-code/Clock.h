#pragma once
#include <chrono>
/**
 *@class Clock
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This class is responsible for mananging the  clock or the stop watch.
 \version 3.0
*/
class Clock
{
public:
    /** \brief Default Constructor. Creates Clock object.
    */
	Clock();

    /**
    *  @brief This function is resets the time lapse after instanting the time back to 0.
    *  @return void
    */
	void Reset();

    /**
    * @brief This function tracks the Time Lapse after instatiation of the code or objects
    *  @return float in seconds.
    */
	float TimeLapse();//Time lapse after instantianting

private:
	std::chrono::steady_clock::time_point StartTime;
	std::chrono::steady_clock::time_point Now;
};

