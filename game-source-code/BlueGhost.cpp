#include "BlueGhost.h"
#include "PacMan.h"
#include <iostream>
#include <cstdlib>
#include <cmath>


using std::pow;


BlueGhost::BlueGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
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

    auto distance=sqrt(pow(Xcoord - XcoordGhost, 2) +
                pow(Ycoord - YcoordGhost, 2) * 1.0);
    distance=abs(distance);
    std::cout << "Distance" <<distance<< std::endl;
    if(distance<400)
    {
      Navigator.SetTarget(*PacManPosition);
    }




      }


