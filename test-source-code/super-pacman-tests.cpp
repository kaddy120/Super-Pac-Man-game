#include "../game-source-code/Collision.h"
#include "../game-source-code/CircleSprite.h"
#include "../game-source-code/PacMan.h"
#include "../game-source-code/Sprite.h"
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

PacMan pacplayer_(35, 35, Vector2(300, 300));
const Sprite positionObj;
TEST_CASE("Check if player moves right")
{
  auto positionX=positionObj.SetPosition(Vector2(300, 300));
  auto currentXPosition=pacplayer_.GetPostion().X;
  pacplayer_.MoveRight();
  CHECK((currentXPosition+1) ==pacplayer_.GetPosition().X);
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
