#include "MapEntiesToDTO.h"

void MapEntiesToDTO::MapTextModelView(
    TextModelView& modelView,
    const PacMan& pacMan,
    const int& highestScore,
    const unsigned int& level)
{
    modelView.Lives = std::to_string(pacMan.GetLifes());
    modelView.HighestScore = std::to_string(highestScore);
    modelView.Level = std::to_string(level);
    modelView.CurrentScore = std::to_string(pacMan.GetPoints());
}

void MapEntiesToDTO::MapPacManModelView(PacManModelView& modelView, const PacMan& pacMan, const Direction& currentDirection)
{
    modelView.Direction = currentDirection;
    modelView.Positon = pacMan.GetPosition();
    auto [width, height] = pacMan.getDimentions();
    modelView.Dimention = Vector2(width, height);
    modelView.State = pacMan.GetState();
}
void MapEntiesToDTO::MapGhostModelView(vector<GhostModelView>& modelView, const vector<std::unique_ptr<AbstractGhost>>& Ghosts)
{
    for (auto i = 0; i < Ghosts.size(); i++)
    {
        GhostModelView tempModel;
        tempModel.Positon = Ghosts[i]->GetPosition();
        tempModel.Dimention = Ghosts[i]->GetPosition();
        tempModel.Mode = Ghosts[i]->GetMode();
        tempModel.Title = Ghosts[i]->Name();
        modelView.push_back(tempModel);
    }
}
void MapEntiesToDTO::MapStaticEntitiesModelView(vector<SpriteModelView>& modelView, const vector<Sprite>& rectSprites)
{
    auto model = SpriteModelView{};
    for (auto rectSprite : rectSprites)
    {
        MapStaticEntitiesModelView(modelView, rectSprite);
    }
}
void MapEntiesToDTO::MapStaticEntitiesModelView(vector<SpriteModelView>& modelView, const CircleSprite& circleSprite)
{
    SpriteModelView Model;

    Model.Title = circleSprite.Name();
    auto radius = circleSprite.GetRadius();
    Model.Dimention = Vector2(radius * 2, radius * 2);
    Model.Positon = circleSprite.GetPosition();
    modelView.push_back(Model);
}
void MapEntiesToDTO::MapStaticEntitiesModelView(vector<SpriteModelView>& modelView, const Sprite& rectSprite)
{
    SpriteModelView Model;

    Model.Title = rectSprite.Name();
    auto [width, height] = rectSprite.getDimentions();
    Model.Dimention = Vector2(width, height);
    Model.Positon = rectSprite.GetPosition();
    modelView.push_back(Model);
}
