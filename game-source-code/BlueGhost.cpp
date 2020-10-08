#include "BlueGhost.h"
#include "PacMan.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


using std::pow;


BlueGhost::BlueGhost(
	const std::vector<CircularEntity>& turningTiles,
	const std::vector<RectangularEntity>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : AbstractGhost(turningTiles,walls, Doors, radius,initPosition) {
    ScatterPosition = Vector2(0, 900.f);
	this->Name("BlueGhost");
}
void BlueGhost::SetTarget()
{
    auto Xcoord=PacManPosition->X;
    auto Ycoord=PacManPosition->Y;
    auto XcoordGhost= this->GetPosition().X;
    auto YcoordGhost=this->GetPosition().Y;

    auto distance=pow(Xcoord - XcoordGhost, 2) + pow(Ycoord - YcoordGhost, 2);
    if (distance < pow(200, 2))
    {
        Navigator.SetTarget(*PacManPosition);
    }
    else
    {
        auto x = rand() % 900;
        auto y = rand() % 900;
        Navigator.SetTarget(Vector2(x, y));
    }
        
}


