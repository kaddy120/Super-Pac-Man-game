#include "../game-source-code/Collision.h"
#include "../game-source-code/CircleSprite.h"
#include "../game-source-code/PacMan.h"
#include "../game-source-code/Sprite.h"
#include "../game-source-code/Key.h"
#include "../game-source-code/Door.h"
#include "../game-source-code/fruit.h"
#include "../game-source-code/FileReader.h"
#include "../game-source-code/Clock.h"
#include "../game-source-code/GameMap.h"
#include "../game-source-code/MapEntitiesToDTO.h"
#include "../game-source-code/ModelViews.h"
#include "../game-source-code/Application.h"
#include "../game-source-code/AbstractGhost.h"
#include "../game-source-code/RedGhost.h"
#include "../game-source-code/BlueGhost.h"
#include "../game-source-code/PinkGhost.h"
#include "../game-source-code/YellowGhost.h"
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
// ----------------Testing Clock --------------------------------------
TEST_CASE("Time lapse should always be greater than 0")
{
    Clock Clock_{};
    Sleep(10);
    CHECK(Clock_.TimeLapse() > 0);
}

TEST_CASE("Time lapse should increase over time")
{
    Clock Clock_{};
    auto TimeLapse1 = Clock_.TimeLapse();
    auto TimeLapse2 = Clock_.TimeLapse();
    CHECK(TimeLapse2 > TimeLapse1);
}
//-----------------Testing Movement Class -----------------------------

TEST_CASE("There's no movement if an intitial dirrection is not specified")
{
    Direction Direction_;
    std::shared_ptr<Vector2> InitPosition = std::make_shared<Vector2>(0,0);
    auto PositionBeforeMove = *InitPosition;
    Movement Movement_{};
    Movement_.SetSpeed(2);
    Movement_.Move(InitPosition, Direction_);
    CHECK(PositionBeforeMove == *InitPosition);
}

TEST_CASE("Moving a position Downwards correctly")
{
    auto Direction_ = Direction::Down;
    std::shared_ptr<Vector2> InitPosition = std::make_shared<Vector2>(0,0);
    auto PositionBeforeMove = *InitPosition;
    Movement Movement_{};
    auto speed = 2;
    Movement_.SetSpeed(speed);
    Movement_.Move(InitPosition, Direction_);
    CHECK(PositionBeforeMove.add(Vector2(0, speed)) == *InitPosition);
}

TEST_CASE("Moving a position to the right correctly")
{
    auto Direction_ = Direction::Right;
    std::shared_ptr<Vector2> InitPosition = std::make_shared<Vector2>(0, 0);
    auto PositionBeforeMove = *InitPosition;
    Movement Movement_{};
    auto speed = 2;
    Movement_.SetSpeed(speed);
    Movement_.Move(InitPosition, Direction_);
    CHECK(PositionBeforeMove.add(Vector2(speed, 0)) == *InitPosition);
}

TEST_CASE("Moving to a position to the left correctly")
{
    auto Direction_ = Direction::Left;
    std::shared_ptr<Vector2> InitPosition = std::make_shared<Vector2>(0, 0);
    auto PositionBeforeMove = *InitPosition;
    Movement Movement_{};
    auto speed = 2;
    Movement_.SetSpeed(speed);
    Movement_.Move(InitPosition, Direction_);
    CHECK(PositionBeforeMove.subtract(Vector2(speed, 0)) == *InitPosition);
}

TEST_CASE("Moving to a aposition to the Upwards correctly")
{
    auto Direction_ = Direction::Up;
    std::shared_ptr<Vector2> InitPosition = std::make_shared<Vector2>(0, 0);
    auto PositionBeforeMove = *InitPosition;
    Movement Movement_{};
    auto speed = 2;
    Movement_.SetSpeed(speed);
    Movement_.Move(InitPosition, Direction_);
    CHECK(PositionBeforeMove.subtract(Vector2(0, speed)) == *InitPosition);
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

TEST_CASE("PacMan start with Initial Points(Score) of zero")
{
    auto width = 35, height = 35;
    PacMan PacMan(width, height, Vector2(0, 0));
    CHECK(PacMan.GetPoints() == 0);
}


TEST_CASE("Points(Score) are incremented correctly")
{
    auto width = 35, height = 35;
    PacMan PacMan(width, height, Vector2(0, 0));
    auto initScore = PacMan.GetPoints();
    PacMan.IncreamentPoints(18);
    CHECK(initScore + 18 == PacMan.GetPoints());
}

TEST_CASE("PacMan Intial has 3 Lives")
{
    auto width = 35, height = 35;
    PacMan PacMan(width, height, Vector2(0, 0));
    CHECK(PacMan.GetLifes() == 3);
}

TEST_CASE("PacMan loss a life when he dies")
{
    auto width = 35, height = 35;
    PacMan PacMan(width, height, Vector2(0, 0));
    auto InitLives = PacMan.GetLifes();
    PacMan.Die();
    CHECK(InitLives-1 == PacMan.GetLifes());
}

TEST_CASE("PacMan Lives should never be less than 0")
{
    auto width = 35, height = 35;
    PacMan PacMan(width, height, Vector2(0, 0));
    PacMan.Die();
    PacMan.Die();
    PacMan.Die();
    PacMan.Die();
    CHECK(PacMan.GetLifes() >= 0);
}

TEST_CASE("PacMan Score is reset to 0 when PacMan loses all lives")
{
    auto width = 35, height = 35;
    PacMan PacMan(width, height, Vector2(0, 0));
    PacMan.IncreamentPoints(10);
/////
    PacMan.Die();
    PacMan.Die();
    PacMan.Die();
    CHECK(PacMan.GetPoints() == 0);
}

TEST_CASE("If PacMan dies 3 times, pacMan state changes from State::Alive to State::Dead")
{
    auto width = 35, height = 35;
    PacMan PacMan(width, height, Vector2(0, 0));
    PacMan.IncreamentPoints(10);
    CHECK(PacMan.GetState() == State::Alive);
    /////
    PacMan.Die();
    PacMan.Die();
    PacMan.Die();
    CHECK(PacMan.GetState()==State::Dead);
}


////------------Test Collision ---------
TEST_CASE("Two rectangles closer to each other collide")
{
    auto width = 40;
    auto height = 40;
    Sprite rectangle1(width, height, Vector2(0, 0));
    Sprite rectangle2(width, height, Vector2(10, 10));
    CHECK(Collision::CheckCollision(rectangle1, rectangle2));
}

TEST_CASE("Two rectangles apart cannot to collide")
{
    Sprite rectangle1(40, 20, Vector2(0, 0));
    Sprite rectangle2(40, 40, Vector2(100, 100));
    CHECK_FALSE(Collision::CheckCollision(rectangle1, rectangle2));
}

TEST_CASE("Two rectangles with touching edges collide")
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
//
TEST_CASE("Two circles apart do not collide")
{
    auto radius = 40;
    CircleSprite rectangle1(radius, Vector2(0, 0));
    CircleSprite rectangle2(radius, Vector2(100, 100));
    CHECK_FALSE(Collision::CheckCollision(rectangle1, rectangle2));
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

TEST_CASE("circle and a square that are 1px apart do not collide")
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

TEST_CASE("circle and a square that are only touching by edges collide")
{
    auto width = 40;
    auto height = 40;
    Sprite rectangle1(width, height, Vector2(0, 0));
    auto radius = 20.f;
    CircleSprite rectangle2(radius, Vector2(60, 0));
    CHECK(Collision::CheckCollision(rectangle2, rectangle1));
}

TEST_CASE("circles of different radius closer to each other collides")
{
    auto radius1 = 40;
    auto radius2 = 12;
    CircleSprite rectangle1(radius1, Vector2(0, 0));
    CircleSprite rectangle2(radius2, Vector2(50, 40));
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
TEST_CASE("Door Object can only be unlocked with the key assigned to it")
{
    Key key1{};
    auto width = 1, height = 3;
    auto position = Vector2(0, 0);
    Door Door1(width, height, position);
    Door1.AssignKey(key1);
    Door1.Unlock(key1);
    CHECK_FALSE(Door1.IsDoorLocked());
}

TEST_CASE("Doors wil not unlock with an incorrect key")
{
    Key key1{};
    Key IncorrectKey{};
    Key IncorrectKey2{};
    auto width = 1, height = 3;
    auto position = Vector2(0, 0);
    Door Door1(width, height, position);
    Door1.AssignKey(key1);
    Door1.Unlock(IncorrectKey);
    CHECK(Door1.IsDoorLocked());
    
    Door1.Unlock(IncorrectKey2);
    CHECK(Door1.IsDoorLocked());
}

//------------Test fruit ---------------
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

//------------Test Mappping of Entities to DTO(Data Transfer Objects)------------------
TEST_CASE("PacMan is mapped to PacManViewModel(DTO) correctly")
{
    PacManViewModel PacManViewModel_;
    auto width = 20.f, height = 20.f;
    auto PacManPosition = Vector2(20, 50);
    PacMan PacMan_(width, height, PacManPosition);
    auto PacManDirection = Direction::Right;
    MapEntitiesToDTO::MapPacManViewModel(PacManViewModel_,PacMan_, PacManDirection);

    CHECK(PacManViewModel_.Dimention == Vector2(width, height));
    CHECK(PacManViewModel_.Direction == PacManDirection);
    CHECK(PacManViewModel_.Positon == PacManPosition);
    CHECK(PacManViewModel_.Title == PacMan_.Name());
    CHECK(PacManViewModel_.State == PacMan_.GetState());
}

TEST_CASE("TextViewModel is correctly filled")
{
    PacManViewModel PacManViewModel_;
    auto width = 20.f, height = 20.f;
    auto PacManPosition = Vector2(20, 50);
    PacMan PacMan_(width, height, PacManPosition);
    auto TextViewModel = TextModelView{};
    auto HighestScore = 30;
    auto Level = 2;
    MapEntitiesToDTO::MapTextViewModel(TextViewModel, PacMan_, HighestScore, Level);
    CHECK(TextViewModel.CurrentScore == std::to_string(PacMan_.GetPoints()));
    CHECK(TextViewModel.HighestScore == std::to_string(HighestScore));
    CHECK(TextViewModel.Level == std::to_string(Level));
    CHECK(TextViewModel.Lives == std::to_string(PacMan_.GetLifes()));
}

TEST_CASE("Static Entites are Mapped correctly")
{
    std::vector<StaticEntitesViewModel> ViewModel;
    auto width = 60, height = 8;
    auto position = Vector2{ 0,0 };

    SUBCASE("Wall is correctly mapped to StaticEntitiesViewModel")
    {
        auto Wall = Sprite(width,height,position);
        MapEntitiesToDTO::MapStaticEntitiesModelView(ViewModel, Wall);
        CHECK(ViewModel[0].Dimention == Vector2(width, height));
        CHECK(ViewModel[0].Positon == position);
        CHECK(ViewModel[0].Title == Wall.Name());
    }
    
    SUBCASE("Wall is correctly mapped to StaticEntitiesViewModel")
    {
        auto Door_ = Door(width, height, position);
        MapEntitiesToDTO::MapStaticEntitiesModelView(ViewModel, Door_);
        CHECK(ViewModel[0].Dimention == Vector2(width, height));
        CHECK(ViewModel[0].Positon == position);
        CHECK(ViewModel[0].Title == Door_.Name());
    }
    
    SUBCASE("Fruit is mapped correctly to StaticEntitiesViewModel")
    {
        auto radius = 15;
        auto Fruit_ = Fruit(radius, position);
        MapEntitiesToDTO::MapStaticEntitiesModelView(ViewModel, Fruit_);
        CHECK(ViewModel[0].Dimention == Vector2(radius*2, radius*2));
        CHECK(ViewModel[0].Positon == position);
        CHECK(ViewModel[0].Title == Fruit_.Name());
    }

    SUBCASE("Pallet is mapped correctly to StaticEntitiesViewModel")
    {
        auto radius = 15;
        auto Pallet_ = SuperPallet(radius, position);
        MapEntitiesToDTO::MapStaticEntitiesModelView(ViewModel, Pallet_);
        CHECK(ViewModel[0].Dimention == Vector2(radius * 2, radius * 2));
        CHECK(ViewModel[0].Positon == position);
        CHECK(ViewModel[0].Title == Pallet_.Name());
    }
}

TEST_SUITE("Application Logic (Integration Test of the whole game Logic)")
{
    
    TEST_CASE("PacMan Can not pass through the Walls")
    {
        std::vector<std::shared_ptr<Door>> Doors;
        SUBCASE("PacMan cannot move Up if there is a horizontal wall on top of pacMan")
        {
            auto WallWidth = 60.f, WallHeight = 8.f;
            auto position = Vector2{ 0,0 };
            auto HorizontalWall_ = Sprite{ WallWidth, WallHeight, position };
            std::vector<Sprite> Walls{ HorizontalWall_ };
            auto Logic = Application(Walls, Doors);
            auto PacManInitPosition = Vector2(10, 9);
            auto PacMan_ = PacMan{35, 35, PacManInitPosition}; //pacMan is positioned slightly underneath a HorizontalWall_
            Logic.MovePacMan(PacMan_, Direction::Up, 0);
            CHECK(PacMan_.GetPosition() == PacManInitPosition);
        }

        SUBCASE("PacMan cannot move to the left if there's a verical wall on the left side of pacMan")
        {
            auto WallWidth = 8.f, WallHeight = 60.f;
            auto position = Vector2{ 0,0 };
            auto VerticalWall_ = Sprite{ WallWidth, WallHeight, position };
            std::vector<Sprite> Walls{ VerticalWall_};
            auto Logic = Application(Walls, Doors);
            auto PacManInitPosition = Vector2(8.5, 9);
            auto PacMan_ = PacMan{ 35, 35, PacManInitPosition }; //pacMan is positioned slightly underneath a HorizontalWall_
            Logic.MovePacMan(PacMan_, Direction::Left, 0);
            CHECK(PacMan_.GetPosition() == PacManInitPosition);
        }
        
        SUBCASE("PacMan cannot move to the Right if there's a verical wall on the Right side of pacMan")
        {
            auto WallWidth = 8.f, WallHeight = 60.f;
            auto position = Vector2{ 8,0 };
            auto VerticalWall_ = Sprite{ WallWidth, WallHeight, position };
            std::vector<Sprite> Walls{ VerticalWall_};
            auto Logic = Application(Walls, Doors);
            auto PacManInitPosition = Vector2(7, 9);
            auto PacMan_ = PacMan{ 35, 35, PacManInitPosition }; //pacMan is positioned slightly underneath a HorizontalWall_
            Logic.MovePacMan(PacMan_, Direction::Right, 0);
            CHECK(PacMan_.GetPosition() == PacManInitPosition);
        }

        SUBCASE("PacMan cannot move Up if there is a horizontal wall on top of pacMan")
        {
            auto WallWidth = 60.f, WallHeight = 8.f;
            auto position = Vector2{ 0,100 };
            auto HorizontalWall_ = Sprite{ WallWidth, WallHeight, position };
            std::vector<Sprite> Walls{ HorizontalWall_ };
            auto Logic = Application(Walls, Doors);
            auto PacManInitPosition = Vector2(10, (100-35));
            auto PacMan_ = PacMan{ 35, 35, PacManInitPosition }; //pacMan is positioned slightly underneath a HorizontalWall_
            Logic.MovePacMan(PacMan_, Direction::Down, 0);
            CHECK(PacMan_.GetPosition() == PacManInitPosition);
        }
    }

    TEST_CASE("PacMan can move through an unlocked door")
    {
        std::vector<Sprite> Walls;
        auto DoorWidth = 60.f, DoorHeight = 8.f;
        std::vector<std::shared_ptr<Door>> Doors{ std::make_unique<Door>(DoorWidth, DoorHeight, Vector2(0,0)) };
        auto Logic = Application(Walls, Doors);
        auto PacManInitPosition = Vector2(0, 9.f);
        auto PacMan_ = PacMan{ 35, 35, PacManInitPosition }; //pacMan is positioned slightly underneath a HorizontalWall_
        Logic.MovePacMan(PacMan_, Direction::Up, 0);
        CHECK(PacMan_.GetPosition() == PacManInitPosition);
    }
    TEST_CASE("PacMan cannot move through a locked door")
    {
        std::vector<Sprite> Walls;
        auto DoorWidth = 60.f, DoorHeight = 8.f;
        std::vector<std::shared_ptr<Door>> Doors{ std::make_unique<Door>(DoorWidth, DoorHeight, Vector2(0,0)) };
        auto Key_ = Key{};
        Doors[0]->AssignKey(Key_);
        Doors[0]->Unlock(Key_);
        auto Logic = Application(Walls, Doors);
        auto PacManInitPosition = Vector2(0, 9.f);
        auto PacMan_ = PacMan{ 35, 35, PacManInitPosition }; //pacMan is positioned slightly underneath a HorizontalWall_
        auto speed = 2.f;
        PacMan_.SetSpeed(speed);
        Logic.MovePacMan(PacMan_, Direction::Up, 0);
        CHECK_FALSE(PacMan_.GetPosition() == PacManInitPosition);
        auto newPosition = PacManInitPosition.subtract(Vector2(0, speed));
        CHECK(PacMan_.GetPosition() == newPosition);
    }
    TEST_CASE("Testing Collision of Ghosts and PacMan")
    {
        std::vector<std::unique_ptr<AbstractGhost>> GhostContainer;
        std::vector<Sprite> walls;
        std::vector<std::shared_ptr<Door>> Doors;
        std::vector<CircleSprite> TurningPoints;
        auto Logic = Application(walls, Doors);

        auto position = Vector2(0,0);
        auto PacMan_ = PacMan{ 35, 35, position };
        auto GhostRadius = 20.f;
        GhostContainer.push_back(std::make_unique<RedGhost>(TurningPoints, walls, Doors, GhostRadius, position));

        SUBCASE("")
        {
            auto collision = Logic.PacManAndGhostsCollide(PacMan_,GhostContainer);
            CHECK(collision);
        }

        SUBCASE("pacman ate superpellet")
        {
            PacMan_.SetState(State::SuperCharged);
            auto collision = Logic.PacManAndGhostsCollide(PacMan_, GhostContainer);
            CHECK_FALSE(collision);
        }

        SUBCASE("pacman charged")
        {
            GhostContainer.push_back(std::make_unique<YellowGhost>(TurningPoints, walls, Doors, GhostRadius , Vector2(300, 300)));
            PacMan_.SetState(State::charged);
            GhostContainer[0]->UpdateMode(Mode::Frightened);
            GhostContainer[1]->UpdateMode(Mode::Frightened);
            auto collision = Logic.PacManAndGhostsCollide(PacMan_, GhostContainer);
            CHECK(collision);
            CHECK(GhostContainer[0]->GetMode() == Mode::Eaten);
            CHECK(GhostContainer[1]->GetMode() == Mode::Frightened);
        }
    }
    TEST_SUITE("")
    {
        
        TEST_CASE("")
        {
            std::vector<Fruit> Fruits;
            auto FruitRadius = 15.f;
            auto Points = 20;
            Fruits.push_back(Fruit(FruitRadius, Vector2(0, 0), Points));
            Fruits.push_back(Fruit(FruitRadius, Vector2(0, 80), Points));
            //Fruit has default point of 10;
            auto Logic = Application{};
            SUBCASE("")
            {
                auto PacMan_ = PacMan{ 35,35, Vector2(300, 300)};
                auto InitScore = PacMan_.GetPoints();
                auto InitNumberOfFruits = Fruits.size();
                Logic.EatFruits(PacMan_, Fruits);
                CHECK(InitScore == PacMan_.GetPoints());
                CHECK(InitNumberOfFruits == Fruits.size());
            }
            SUBCASE("")
            {
                auto PacMan_ = PacMan{ 35,35, Vector2(0, 0) };
                auto InitScore = PacMan_.GetPoints();
                auto InitNumberOfFruits = Fruits.size();
                Logic.EatFruits(PacMan_, Fruits);
                CHECK(InitScore+Points == PacMan_.GetPoints());
                CHECK(InitNumberOfFruits -1 == Fruits.size());
            }
        }
        TEST_CASE("")
        {

            /* bool AtePallet(PacMan & pacMan, std::vector<SuperPallet> & pallet);*/
        }

        TEST_CASE("")
        {
            //void OpenDoors(const PacMan & pacMan, std::vector<Key> & keys, vector<std::shared_ptr<Door>> & Doors);

        }
        TEST_CASE("")
        {
            //void MovablesExitMaze(IEntity & MovableEntity, const unsigned int& mazeWidth);
        }
        TEST_CASE("")
        {
            //void MovablesExitMaze(IEntity & MovableEntity, const unsigned int& mazeWidth);
        }
    }
    }
    

