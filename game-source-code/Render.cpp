#include "Render.h"

Render::Render(const std::shared_ptr<sf::RenderWindow>& window) : window(window)
{
	//i should load resouces
    if (!PacManTexture.loadFromFile("resources/Pacman.png")) throw FaildeToLoadResourceException{};
    if (!GhostsTexture.loadFromFile("resources/Ghost.png")) throw FaildeToLoadResourceException{};
    if (!FruitsTextutre.loadFromFile("resources/Fruit.png")) throw FaildeToLoadResourceException{};
    if (!keyTexture.loadFromFile("resources/Keys.png")) throw FaildeToLoadResourceException{};
}

void Render::RenderStaticSprites(const std::vector<SpriteModelView>& spriteModelView)
{
}
void Render::RenderText(const TextModelView& textModelView)
{

}

void Render::RenderGhost(const vector<GhostModelView>& ghostModelView)
{
}
void Render::RenderPacMan(const PacManModelView& pacManModelVIew)
{
}
void Render::RenderSplashScreen()
{
}
void Render::RenderEndGameScreen()
{
}

void Render::RenderDoors()
{
}

void Render::RenderKeys()
{
}

void Render::RenderFruits()
{
}
void Render::RenderGhosts()
{
}
void Render::RenderPacMan()
{
}
