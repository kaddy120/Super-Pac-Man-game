#include "Render.h"

Render::Render(const std::shared_ptr<sf::RenderWindow>& window_) :
    window(window_)
{
	//i should load resouces
    if (!PacManTexture.loadFromFile("resources/Pacman.png")) throw FaildeToLoadResourceException{};
    if (!GhostsTexture.loadFromFile("resources/Ghosts.png")) throw FaildeToLoadResourceException{};
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
            RenderRectangleShape(modelView, Fruit);
        }
        else if (modelView.Title == "Key")
        {
            RenderRectangleShape(modelView, Key);
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

void Render::RenderGhost(const vector<GhostModelView>& ghostModelView, const float& deltaTIme)
{
    //i have violated dry princple here, i'll need to fix it
    for (auto model : ghostModelView)
    {
        if (model.Title =="RedGhost")
        {
            GhostAnimation.Update(0, deltaTIme);
            GhostSprite.setTextureRect(GhostAnimation.GetIntRect());
            auto position = model.Positon;
            GhostSprite.setPosition(sf::Vector2f(position.X, position.Y));
            window->draw(GhostSprite);
        }
        else if (model.Title =="PinkGhost")
        {
            GhostAnimation.Update(1, deltaTIme);
            GhostSprite.setTextureRect(GhostAnimation.GetIntRect());
            auto position = model.Positon;
            GhostSprite.setPosition(sf::Vector2f(position.X, position.Y));
            window->draw(GhostSprite);
        }
        else if (model.Title == "BlueGhost")
        {
            GhostAnimation.Update(2, 0);
        }
        else if (model.Title=="YellowGhost")
        {
            GhostAnimation.Update(3, 0);
            GhostSprite.setTextureRect(GhostAnimation.GetIntRect());
            auto position = model.Positon;
            GhostSprite.setPosition(sf::Vector2f(position.X, position.Y));
            window->draw(GhostSprite);
        }
    }
}
void Render::RenderPacMan(const PacManModelView& pacManModelVIew, const float& deltaTime)
{
    PacManAnimation.Update(0, deltaTime);
    PackManSprite.setTextureRect(PacManAnimation.GetIntRect());
    auto position = pacManModelVIew.Positon;
    PackManSprite.setPosition(sf::Vector2f(position.X, position.Y));
    //PackManSprite.setRotation(90);
    window->draw(PackManSprite);
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
    PackManSprite.setSize(sf::Vector2f(50,50));
    PackManSprite.setTexture(&PacManTexture);
    GhostSprite.setSize(sf::Vector2f(45, 45));
    GhostSprite.setOrigin(sf::Vector2f(20, 20));
    GhostSprite.setTexture(&GhostsTexture);
    Fruit.setSize(sf::Vector2f(50, 50));
    Fruit.setTexture(&FruitsTextutre);
    Key.setSize(sf::Vector2f(50,30));
    Key.setTexture(&keyTexture);
    Door.setFillColor(sf::Color(153, 94, 0));

//============test to assign this in a constructure==========
    Animation temp{ &GhostsTexture, sf::Vector2u(8,5), 0.6f };
    GhostAnimation = temp;
    Animation temp2{ &PacManTexture, sf::Vector2u(3,1), 0.2f };
    PacManAnimation = temp2;
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
