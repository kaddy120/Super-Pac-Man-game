#include "GameEndScreen.h"

GameEndScreen::GameEndScreen(const std::shared_ptr<sf::RenderWindow>& Window_, const bool& won)
{
    sf::Font font;
    if(!font.loadFromFile("resources/sansation.ttf"));
    {}
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    auto FontSize = 70u;
    pauseMessage.setCharacterSize(FontSize);
    pauseMessage.setPosition(50.f, 200.f);
    pauseMessage.setFillColor(sf::Color::White);

    if( !(file_image.loadFromFile("resources/background.jpg")) )
    {
        return;
    }
    sf::Sprite gameover(file_image);
    gameover.scale(0.5f,1.0f);
    if (won)
    {
        pauseMessage.setString("You won!\n\n\nPress Enter to\n\n move to the next Level\n\n Press Esc to exit \n");
        Window_->draw(gameover);
    }
    else
    {
        pauseMessage.setString("You lose!\n\n\nPress Enter to Replay\n\n Press Esc to exit \n");
       Window_->draw(gameover);
    }
    Window_->draw(pauseMessage);
    Window_->display();

    while (Window_->isOpen())
    {
        // Handle events
        sf::Event event;
        while (Window_->pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                Window_->close();
                break;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter))
            {
                return;
            }
        }
    }
}
