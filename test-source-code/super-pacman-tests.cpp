#include "../game-source-code/Collision.h"
#include "../game-source-code/CircleSprite.h"
#include "../game-source-code/PacMan.h"
#include "../game-source-code/Sprite.h"
#include "../game-source-code/Key.h"
#include "../game-source-code/Door.h"
#include "../game-source-code/fruit.h"
#include "../game-source-code/FileReader.h"
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
//
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
  PacMan.Move(Direction::Right);
  CHECK(PositionBeforeMove.add(Vector2(Speed,0)) == PacMan.GetPosition());
}
//
TEST_CASE("PacMan is moving to the Right correctly")
{
    PacMan PacMan(35, 35, Vector2(300, 300));
    auto PositionBeforeMove = PacMan.GetPosition();
    auto Speed = 2.f;
    PacMan.SetSpeed(Speed);
    PacMan.Move(Direction::Right);
    CHECK(PositionBeforeMove.add(Vector2(Speed, 0)) == PacMan.GetPosition());
}

TEST_CASE("PacMan is moving to the Left correctly")
{
    PacMan PacMan(35, 35, Vector2(300, 300));
    auto PositionBeforeMove = PacMan.GetPosition();
    auto Speed = 2.f;
    PacMan.SetSpeed(Speed);
    PacMan.Move(Direction::Left);
    CHECK(PositionBeforeMove.subtract(Vector2(Speed, 0)) == PacMan.GetPosition());
}

TEST_CASE("PacMan is moving Down correctly")
{
    PacMan PacMan(35, 35, Vector2(300, 300));
    auto PositionBeforeMove = PacMan.GetPosition();
    auto Speed = 2.f;
    PacMan.SetSpeed(Speed);
    PacMan.Move(Direction::Down);
    CHECK(PositionBeforeMove.add(Vector2(0,Speed)) == PacMan.GetPosition());
}

TEST_CASE("PacMan is moving Up correctly")
{
    PacMan PacMan(35, 35, Vector2(300, 300));
    auto PositionBeforeMove = PacMan.GetPosition();
    auto Speed = 2.f;
    PacMan.SetSpeed(Speed);
    PacMan.Move(Direction::Up);
    CHECK(PositionBeforeMove.subtract(Vector2(0, Speed)) == PacMan.GetPosition());
}

TEST_CASE("position of the PacMan can be tracked using shared pointer as it changes")
{
    PacMan PacMan(35, 35, Vector2(300, 450));
    auto PacManPosition_ptr = PacMan.GetPosition_ptr();
    PacMan.SetPosition(Vector2(40, 60));
    CHECK(Vector2(40, 60) == *PacManPosition_ptr);
    PacMan.Move(Direction::Down);
    PacMan.Move(Direction::Left);
    CHECK(PacMan.GetPosition() == *PacManPosition_ptr);
}
//
////------------Test Collision ---------
TEST_CASE("Two rectangles closer to each other collide")
{
    auto width = 40;
    auto height = 40;
    Sprite rectangle1(width, height, Vector2(0, 0));
    Sprite rectangle2(width, height, Vector2(10, 10));
    CHECK(Collision::CheckCollision(rectangle1, rectangle2));
}

TEST_CASE("Two rectangles touching by edges collide")
{
    auto width = 40;
    auto height = 40;
    Sprite rectangle1(width, height, Vector2(0, 0));
    Sprite rectangle2(width, height, Vector2(40, 0));
    CHECK(Collision::CheckCollision(rectangle1, rectangle2));
}

TEST_CASE("Testing if two circles collide ")
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


TEST_CASE("circle and a square do not collide if they are far apart ")
{
    auto width = 40;
    auto height = 40;
    Sprite rectangle1(width, height, Vector2(0, 0));
    auto radius = 20.f;
    CircleSprite rectangle2(radius, Vector2(70, 0));
    CHECK_FALSE(Collision::CheckCollision(rectangle2, rectangle1));
}

TEST_CASE("circle and a square that are 1px apart do")
{
    auto width = 40;
    auto height = 40;
    Sprite rectangle1(width, height, Vector2(0, 0));
    auto radius = 20.f;
    CircleSprite Circle1(radius, Vector2(61, 0));
    CircleSprite Circle2(radius, Vector2(0, 61));
    CHECK_FALSE(Collision::CheckCollision(Circle1, rectangle1));
    CHECK_FALSE(Collision::CheckCollision(Circle2, rectangle1));
}

TEST_CASE("circle and a square that are 1px apart do")
{
    auto width = 40;
    auto height = 40;
    Sprite rectangle1(width, height, Vector2(0, 0));
    auto radius = 20.f;
    CircleSprite rectangle2(radius, Vector2(60, 0));
    CHECK(Collision::CheckCollision(rectangle2, rectangle1));
}
TEST_CASE("circles do not collide if they are far apart")
{
    auto radius = 40;
    CircleSprite rectangle1(radius, Vector2(0, 0));
    CircleSprite rectangle2(radius, Vector2(100, 100));
    CHECK_FALSE(Collision::CheckCollision(rectangle1, rectangle2));
}
TEST_CASE("circles of different radius closer to each other collides")
{
    auto radius1 = 40;
    auto radius2 = 12;
    CircleSprite rectangle1(radius1, Vector2(0, 0));
    CircleSprite rectangle2(radius2, Vector2(50, 40));
    CHECK_FALSE(Collision::CheckCollision(rectangle1, rectangle2));
}

TEST_CASE("Two rectangles apart cannot to collide")
{
    Sprite rectangle1(40, 40, Vector2(0, 0));
    Sprite rectangle2(40, 40, Vector2(100, 100));
    CHECK_FALSE(Collision::CheckCollision(rectangle1, rectangle2));
}


//-----------Test Key-----------------

TEST_CASE("Key's ID is equal to number of keys' Objects")
{
    Key key1{};
    Key key2{};
    Key Key3{};
    CHECK(key1.GetKeyId() == "1");
    CHECK(key2.GetKeyId() == "2");
    CHECK(Key3.GetKeyId() == "3");
}

TEST_CASE("Every Key object has unique ID")
{
    Vector2 position(0.f,0.f);
    auto radius = 15.f;
    Key key1(radius,position);
    Key key2(radius, position);
    CHECK_FALSE(key1.GetKeyId()==key2.GetKeyId());
}

TEST_CASE("Keys object objects are not equal because or their unique IDs")
{
    Key key1{};
    Key key2{};
    CHECK_FALSE(key1 == key2);
}

//------------Test Door ------------

TEST_CASE("A door object instant is locked by default")
{
    auto width = 1, height = 3;
    auto position = Vector2(0, 0);
    Door Door1(width, height, position);
    CHECK(Door1.IsDoorLocked());
}
TEST_CASE("Door Object can only be unlocked with a key assigned to it")
{
    Key key1{};
    auto width = 1, height = 3;
    auto position = Vector2(0, 0);
    Door Door1(width, height, position);
    Door1.AssignKey(key1);
    Door1.Unlock(key1);
    CHECK_FALSE(Door1.IsDoorLocked());
}

TEST_CASE("Two doors can be in the same position")
 {
    Door door_;
    auto door1=door_.GetPosition_ptr();
    auto door2=door_.GetPosition_ptr();
    CHECK(door1 == door2);
}
TEST_CASE("Two doors cannot have same key")
 {
//Door door_;
//  auto door1= door_.;
//  auto door2=door_.AssignKey();
//    CHECK(door1 == door2);
}
//------------Test fruit ------------
TEST_CASE("Fruits points are correct and can be modified")
{
//Vector2 vector2(2.f,3.f);
//Fruit fruit_(10.f,vector2);
//int fruit_point=10;
//auto modifiedfruitpoint=fruit_(10.f,vector2).FruitPoints(10);
//CHECK_FALSE(fruit_point==modifiedfruitpoint);


}
////------------Test Score File Reader ------------

TEST_CASE("FileReader can set and retrieve the Highest score successfully from a textfile")
{
    FileReader score_reader_file{};
    auto highScore = 250;
    score_reader_file.setHighestScore(highScore);

    CHECK(highScore == score_reader_file.getHighestScore());
}
TEST_CASE("A score can never be less than 0 set and retrived from a textfile")
{
     FileReader score_reader_file{};
     auto highScore = -1;
    score_reader_file.setHighestScore(highScore);

    CHECK_FALSE(highScore == score_reader_file.getHighestScore());
}
TEST_CASE("An exception is thrown when file is not found"){



}

////------------Test Game Score ------------

