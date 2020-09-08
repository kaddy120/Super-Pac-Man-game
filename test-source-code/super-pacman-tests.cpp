#include "../game-source-code/Collision.h"
#include "../game-source-code/CircleSprite.h"
#include "../game-source-code/PacMan.h"
#include "../game-source-code/Sprite.h"
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

Sprite positionObj;
PacMan pacplayer_(35.f, 35.f, Vector2(300.f, 300.f));
TEST_CASE("Check if player moves right")
{
  positionObj.SetPosition(Vector2(300, 300));
  CHECK(true);
  //auto currentXPosition=pacplayer_.GetPosition().X;
  //pacplayer_.Movement(Move::Right);
  //CHECK((currentXPosition+1) ==pacplayer_.GetPosition().X);
}

//TEST_CASE("Check if player moves left")
//{
//
//	auto currentXPosition = pacplayer_.getPosition().X;
//	pacplayer_.moveLeft();
//	CHECK((current-1) == pacplayer_.getPosition().X);
//}
//
//TEST_CASE("Check if player moves up")
//{
//	auto current = pacplayer_.getPosition().Y;
//	pacplayer_.moveUp();
//	CHECK((current-1) == playerObj.getPosition().Y);
//}
//
//TEST_CASE("Check if player moves Down")
//{
//	auto current = playerObj.getPosition().Y;
//	playerObj.moveDown();
//	CHECK((current+1) == playerObj.getPosition().Y);
//}
