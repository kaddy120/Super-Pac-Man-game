#include "../game-source-code/Collision.h"
#include "../game-source-code/CircleSprite.h"
#include "../game-source-code/PacMan.h"
#include "../game-source-code/Sprite.h"
#include "../game-source-code/Key.h"
#include "../game-source-code/Door.h"

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

TEST_CASE("check that vector with the same coordinates are equal")
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

//------------Test Collision ---------
TEST_CASE("Two rectangles closer to each other collide")
{
    Sprite rectangle1(40, 40, Vector2(0, 0));
    Sprite rectangle2(40, 40, Vector2(10, 10));
    CHECK(Collision::CheckCollision(rectangle1, rectangle2));
}

TEST_CASE("Testing if two circles collide")
{
    CircleSprite rectangle1(40, Vector2(0, 0));
    CircleSprite rectangle2(40, Vector2(10, 10));
    CHECK(Collision::CheckCollision(rectangle1, rectangle2));
}

TEST_CASE("Testing if a circle and a square collide ")
{
    Sprite rectangle1(40, 40, Vector2(0, 0));
    CircleSprite rectangle2(40, Vector2(10, 10));
    CHECK(Collision::CheckCollision(rectangle2, rectangle1));
}

TEST_CASE("Testing if a circle and a square cannnot collide if they are far apart ")
{
    Sprite rectangle1(40, 40, Vector2(0, 0));
    CircleSprite rectangle2(40, Vector2(50, 50));
    CHECK_FALSE(Collision::CheckCollision(rectangle2, rectangle1));
}
TEST_CASE("Testing if a two circles cannnot collide if they are far apart")
{
    CircleSprite rectangle1(40, Vector2(0, 0));
    CircleSprite rectangle2(40, Vector2(100, 100));
    CHECK_FALSE(Collision::CheckCollision(rectangle1, rectangle2));
}
TEST_CASE("Two rectangles apart cannot to collide")
{
    Sprite rectangle1(40, 40, Vector2(0, 0));
    Sprite rectangle2(40, 40, Vector2(100, 100));
    CHECK_FALSE(Collision::CheckCollision(rectangle1, rectangle2));
}


//-----------Test Key-----------------




//------------Test Door ------------

