#include "MapEntitiesToDTO.h"

void MapEntitiesToDTO::MapTextViewModel(
    TextModelView& modelView,
    const PacMan& pacMan,
    const int& highestScore,
    const unsigned int& level)
{
    modelView.Lives = std::to_string(pacMan.GetLives());
    modelView.HighestScore = std::to_string(highestScore);
    modelView.Level = std::to_string(level);
    modelView.CurrentScore = std::to_string(pacMan.GetPoints());
}

void MapEntitiesToDTO::MapPacManViewModel(PacManViewModel& modelView, const PacMan& pacMan, const Direction& currentDirection)
{
    modelView.Direction = currentDirection;
    modelView.Positon = pacMan.GetPosition();
    auto [width, height] = pacMan.getDimentions();
    modelView.Dimention = Vector2(width, height);
    modelView.State = pacMan.GetState();
}
void MapEntitiesToDTO::MapGhostModelView(vector<GhostModelView>& modelView, const vector<std::unique_ptr<AbstractGhost>>& Ghosts)
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
void MapEntitiesToDTO::MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const vector<RectangularEntity>& rectRectangularEntitys)
{
    auto model = StaticEntitesViewModel{};
    for (auto rectRectangularEntity : rectRectangularEntitys)
    {
        MapStaticEntitiesModelView(modelView, rectRectangularEntity);
    }
}
void MapEntitiesToDTO::MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const CircularEntity& CircularEntity)
{
    StaticEntitesViewModel Model;

    Model.Title = CircularEntity.Name();
    auto radius = CircularEntity.GetRadius();
    Model.Dimention = Vector2(radius * 2, radius * 2);
    Model.Positon = CircularEntity.GetPosition();
    modelView.push_back(Model);
}
void MapEntitiesToDTO::MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const RectangularEntity& rectRectangularEntity)
{
    StaticEntitesViewModel Model;

    Model.Title = rectRectangularEntity.Name();
    auto [width, height] = rectRectangularEntity.getDimentions();
    Model.Dimention = Vector2(width, height);
    Model.Positon = rectRectangularEntity.GetPosition();
    modelView.push_back(Model);
}
