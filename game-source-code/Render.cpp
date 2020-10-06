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

void Render::RenderStaticSprites(const std::vector<StaticEntitesViewModel>& StaticEntitesViewModel)
{
    for (auto modelView : StaticEntitesViewModel)
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
        else if (modelView.Title == "SuperPallet")
        {
            Pallet.setFillColor(sf::Color(67, 224, 4));
            Pallet.setPosition(sf::Vector2f(modelView.Positon.X, modelView.Positon.Y));
            window->draw(Pallet);
        }
        else if (modelView.Title == "PowerPallet")
        {
            Pallet.setFillColor(sf::Color(190, 10, 245));
            Pallet.setPosition(sf::Vector2f(modelView.Positon.X, modelView.Positon.Y));
            window->draw(Pallet);
        }
    }
}
void Render::RenderText(const TextModelView& textModelView)
{
    FileReader filereader_;
    auto score_str=textModelView.CurrentScore;
    auto highest_ptr=textModelView.HighestScore;
    auto lives=textModelView.Lives;

    GeneralText.setPosition(0.f, 80.f);
    GeneralText.setString("Highest Score: " + highest_ptr);
    window->draw(GeneralText);


    GeneralText.setPosition(0.f, 50.f);
    GeneralText.setString("Current Score : "+ score_str);
    window->draw(GeneralText);


    GeneralText.setPosition(500.f, 50.f);
    GeneralText.setString("Lives Reamaining: "+ lives);
    window->draw(GeneralText);



}

void Render::RenderGhost(const vector<GhostModelView>& ghostModelView, const float& deltaTIme)
{
    auto DrawGhost = [this](GhostModelView model) {
        if (model.Mode == Mode::Eaten)
            GhostAnimation.Update(4, 0);
        GhostSprite.setTextureRect(GhostAnimation.GetIntRect());
        auto position = model.Positon;
        GhostSprite.setPosition(sf::Vector2f(position.X, position.Y));
        window->draw(GhostSprite);
    };

    if (ghostModelView[0].Mode == Mode::Frightened
        || ghostModelView[1].Mode == Mode::Frightened ||
        ghostModelView[2].Mode == Mode::Frightened){

        GhostAnimation.Update(5, deltaTIme);
        for (auto model : ghostModelView){
            if (model.Mode == Mode::Eaten)
                GhostAnimation.Update(4, deltaTIme);
            else
                GhostAnimation.Update(5, 0);
            DrawGhost(model);
        }
        return;
    }
    for (auto model : ghostModelView)
    {
        if (model.Title =="RedGhost")
        {
                GhostAnimation.Update(0, deltaTIme);
            DrawGhost(model);
        }
        else if (model.Title =="PinkGhost")
        {

                GhostAnimation.Update(1, 0);
            DrawGhost(model);
        }
        else if (model.Title == "BlueGhost")
        {
                GhostAnimation.Update(2, 0);
            DrawGhost(model);

        }
        else if (model.Title=="YellowGhost")
        {
                GhostAnimation.Update(3, 0);
            DrawGhost(model);
        }
    }
}
void Render::RenderPacMan(const PacManViewModel& pacManViewModel, const float& deltaTime)
{
    auto DrawPacMan = [this](const PacManViewModel& pacManViewModel) {
        PackManSprite.setTextureRect(PacManAnimation.GetIntRect());
        auto position = pacManViewModel.Positon;
        PackManSprite.setPosition(sf::Vector2f(position.X, position.Y));
    };
    auto D = pacManViewModel.Dimention;
    if (pacManViewModel.State == State::SuperCharged)
    {
        PackManSprite.setOrigin(15, 15);
        PackManSprite.setScale(sf::Vector2f(2,2));
    }
    switch (pacManViewModel.Direction)
    {
    case Direction::Right:
        PacManAnimation.Update(0, deltaTime);
        DrawPacMan(pacManViewModel);
        break;
    case Direction::Left:
        PacManAnimation.Update(3, deltaTime);
        DrawPacMan(pacManViewModel);
        break;
    case Direction::Down:
        PacManAnimation.Update(1, deltaTime);
        DrawPacMan(pacManViewModel);
        break;
    case Direction::Up:
        PacManAnimation.Update(2, deltaTime);
        DrawPacMan(pacManViewModel);
        break;
    default:
        PacManAnimation.Update(1, deltaTime);
        DrawPacMan(pacManViewModel);
        break;
        break;
    }
    window->draw(PackManSprite);
    PackManSprite.setOrigin(0, 0);
    PackManSprite.setScale(sf::Vector2f(1, 1));
}
void Render::RenderSplashScreen()
{
}
void Render::RenderRectangleShape(const StaticEntitesViewModel& modelView, sf::RectangleShape& rect)
{
    auto size_ = modelView.Dimention;
    rect.setSize(sf::Vector2f(size_.X, size_.Y));
    rect.setPosition(sf::Vector2f(modelView.Positon.X, modelView.Positon.Y));
    window->draw(rect);
}

void Render::RenderKeys(const StaticEntitesViewModel& StaticEntitesViewModel)
{
}

void Render::RenderFruits(const StaticEntitesViewModel& StaticEntitesViewModel)
{
}

void Render::Initialise()
{
    PackManSprite.setSize(sf::Vector2f(50,50));
    PackManSprite.setTexture(&PacManTexture);
    PacManTexture.setSmooth(true);
    GhostSprite.setSize(sf::Vector2f(45, 45));
    GhostSprite.setOrigin(sf::Vector2f(20, 20));
    GhostSprite.setTexture(&GhostsTexture);
    Fruit.setSize(sf::Vector2f(50, 50));
    Fruit.setTexture(&FruitsTextutre);
    Key.setSize(sf::Vector2f(50,50));
    Key.setScale(3,4);
    Key.setTexture(&keyTexture);
    Door.setFillColor(sf::Color(153, 94, 0));
    Pallet.setRadius(16.5f);

    Animation temp{ &GhostsTexture, sf::Vector2u(8,6), 0.6f };
    GhostAnimation = temp;
    Animation temp2{ &PacManTexture, sf::Vector2u(3,4), 0.15f };
    PacManAnimation = temp2;

    GeneralText.setFont(font);
    GeneralText.setCharacterSize(25);
    GeneralText.setFillColor(sf::Color::Red);
    LevelText;
    HighestScoreText;
}
void Render::ClearWindow()
{
    window->clear();
}
