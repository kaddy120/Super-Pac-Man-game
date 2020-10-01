#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Application.h"
#include "Sprite.h"
#include "GameMap.h"
#include <vector>
#include <tuple>
#include "PacMan.h"
#include "Collision.h"
#include "RedGhost.h"
#include "SplashScreen.h"
#include "PinkGhost.h"
#include "YellowGhost.h"
#include <fstream>
#include "GameLogic.h"
#include "GameEndScreen.h"

int main()
{
      srand(time(0));
      Window Game_Screan;
      GameLogic gameLogic(Game_Screan.getWindow());
      gameLogic.Run();

      return EXIT_SUCCESS;
}
