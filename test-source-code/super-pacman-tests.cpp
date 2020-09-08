#include "../game-source-code/Collision.h"
#include "../game-source-code/CircleSprite.h"
#include "../game-source-code/PacMan.h"
#include "../game-source-code/Sprite.h"

#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//------------Testing Vector2 --------------------------
TEST_CASE("check that vector2 is initialized correctly")
{
    Vector2 Vector(4.f, 8.6f);
    CHECK(Vector.X == 4.f);
    CHECK(Vector.Y == 8.6f);
}

TEST_CASE("check that vector with same coordinates are equal")
{
    Vector2 Vector1(4.f, 8.f);
    Vector2 Vector2(4.f, 8.f);
    CHECK(Vector1 == Vector2);
}

TEST_CASE("check that vector with differet coordinates are not equal")
{
    Vector2 Vector1(4.f, 8.f);
    Vector2 Vector2(4.f, 500.f);
    CHECK_FALSE(Vector1 == Vector2);
}

//------------------Testing PacMan --------------------------------------

TEST_CASE("Check that PacMan positio is initialised correctly")
{
    auto InitPosition = Vector2(300, 400);
    PacMan PacMan(35, 35, InitPosition);
    CHECK(InitPosition == PacMan.GetPosition());
    CHECK(InitPosition == *PacMan.GetPosition_ptr());
}

TEST_CASE("PacMan is moving to the right correctly")
{
  PacMan PacMan(35, 35, Vector2(300, 300));
  auto PositionBeforeMove = PacMan.GetPosition();
  auto Speed = 2.f; 
  PacMan.SetSpeed(Speed);
  PacMan.Movement(Move::Right);
  CHECK(PositionBeforeMove.add(Vector2(Speed,0)) == PacMan.GetPosition());
}

TEST_CASE("PacMan is moving to the Right correctly")
{
    PacMan PacMan(35, 35, Vector2(300, 300));
    auto PositionBeforeMove = PacMan.GetPosition();
    auto Speed = 2.f;
    PacMan.SetSpeed(Speed);
    PacMan.Movement(Move::Right);
    CHECK(PositionBeforeMove.add(Vector2(Speed, 0)) == PacMan.GetPosition());
}
TEST_CASE("PacMan is moving to the Left correctly")
{
    PacMan PacMan(35, 35, Vector2(300, 300));
    auto PositionBeforeMove = PacMan.GetPosition();
    auto Speed = 2.f;
    PacMan.SetSpeed(Speed);
    PacMan.Movement(Move::Left);
    CHECK(PositionBeforeMove.subtract(Vector2(Speed, 0)) == PacMan.GetPosition());
}
TEST_CASE("PacMan is moving Down correctly")
{
    PacMan PacMan(35, 35, Vector2(300, 300));
    auto PositionBeforeMove = PacMan.GetPosition();
    auto Speed = 2.f;
    PacMan.SetSpeed(Speed);
    PacMan.Movement(Move::Down);
    CHECK(PositionBeforeMove.add(Vector2(0,Speed)) == PacMan.GetPosition());
}

TEST_CASE("PacMan is moving Up correctly")
{
    PacMan PacMan(35, 35, Vector2(300, 300));
    auto PositionBeforeMove = PacMan.GetPosition();
    auto Speed = 2.f;
    PacMan.SetSpeed(Speed);
    PacMan.Movement(Move::Up);
    CHECK(PositionBeforeMove.subtract(Vector2(0, Speed)) == PacMan.GetPosition());
}

TEST_CASE("position of the PacMan can be tracked using shared pointer as it changes")
{
    PacMan PacMan(35, 35, Vector2(300, 450));
    auto PacManPosition_ptr = PacMan.GetPosition_ptr();
    PacMan.SetPosition(Vector2(40, 60));
    CHECK(Vector2(40, 60) == *PacManPosition_ptr);
    PacMan.Movement(Move::Down);
    PacMan.Movement(Move::Left);
    CHECK(PacMan.GetPosition() == *PacManPosition_ptr);
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
