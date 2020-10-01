#include "GameEndScreen.h"

GameEndScreen::GameEndScreen(const std::shared_ptr<sf::RenderWindow>& Window_)
{
    sf::Font font;
    if(!font.loadFromFile("resources/sansation.ttf"));
    {
    }
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(70);
    pauseMessage.setPosition(50.f, 200.f);
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString("Game over !\n\n\nPress Enter to Replay\n\n Press Esc to exit \n");
    if( !(file_image.loadFromFile("resources/background.jpg")) )
    {
        return;
    }
    sf::Sprite gameover(file_image);
    gameover.scale(0.5f,1.0f);

    Window_->draw(gameover);
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


        // Clear the window
        // Window_->clear(sf::Color(0, 0, 0));
        //Window_->draw(pauseMessage);
        // Display things on screen
        //Window_->display();
    }
}
