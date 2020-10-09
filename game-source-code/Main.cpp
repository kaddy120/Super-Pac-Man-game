#include <SFML/Graphics.hpp>

#include "Presentation/Window.h"
#include "Logic/Application.h"
#include "Logic/RectangularEntity.h"
#include "Logic/GameMap.h"
#include <vector>
#include <tuple>
#include "Logic/PacMan.h"
#include "Logic/Collision.h"
#include "Logic/RedGhost.h"
#include "Presentation/SplashScreen.h"
#include "Logic/PinkGhost.h"
#include "Logic/YellowGhost.h"
#include <fstream>
#include "Logic/GameLogic.h"
#include "Presentation/GameEndScreen.h"
//This is main cpp
int main()
{
      srand(time(0));
      Window Game_Screan;
      GameLogic gameLogic(Game_Screan.getWindow());
      gameLogic.Run();

      return EXIT_SUCCESS;
}
