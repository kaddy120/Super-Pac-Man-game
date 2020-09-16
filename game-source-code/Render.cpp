#include "Render.h"

Render::Render(const std::shared_ptr<sf::RenderWindow>& window_) : window(window_)
{
	//i should load resouces
    if (!PacManTexture.loadFromFile("resources/Pacman.png")) throw FaildeToLoadResourceException{};
    if (!GhostsTexture.loadFromFile("resources/Ghost.png")) throw FaildeToLoadResourceException{};
    if (!FruitsTextutre.loadFromFile("resources/Fruit.png")) throw FaildeToLoadResourceException{};
    if (!keyTexture.loadFromFile("resources/Keys.png")) throw FaildeToLoadResourceException{};
    if (!font.loadFromFile("resources/sansation.ttf")) throw FaildeToLoadResourceException{};
    Initialise();
}

void Render::RenderStaticSprites(const std::vector<SpriteModelView>& spriteModelView)
{
    for (auto modelView : spriteModelView)
    {
        if (modelView.Title == "Fruit")
        {
        }
        else if (modelView.Title == "Key")
        {
        }
        else if (modelView.Title == "Door")
        {
            RenderRectangleShape(modelView, Door);
        }
        else if (modelView.Title == "Wall")
        {
            RenderRectangleShape(modelView, Wall);
        }
    }
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

void Render::RenderRectangleShape(const SpriteModelView& modelView, sf::RectangleShape& rect)
{
    auto size_ = modelView.Dimention;
    rect.setSize(sf::Vector2f(size_.X, size_.Y));
    rect.setPosition(sf::Vector2f(modelView.Positon.X, modelView.Positon.Y));
    window->draw(rect);
}

void Render::RenderKeys(const SpriteModelView& spriteModelView)
{
}

void Render::RenderFruits(const SpriteModelView& spriteModelView)
{
}

void Render::Initialise()
{
    PackManSprite.setScale(sf::Vector2f(50,50));
    PackManSprite.setTexture(&PacManTexture);
    GhostSprite.setScale(sf::Vector2f(50, 50));
    GhostSprite.setTexture(&GhostsTexture);
    Fruit.setScale(sf::Vector2f(50, 50));
    Fruit.setTexture(&FruitsTextutre);
    Door.setFillColor(sf::Color(153, 94, 0));
   //set door colour
    font;
    ScoreText;
    LevelText;
    HighestScoreText;
    GeneralText;
}
void Render::ClearWindow()
{
    window->clear();
}
//void Render::RenderGhosts()
//{
//}
//void Render::RenderPacMan()
//{
//}
