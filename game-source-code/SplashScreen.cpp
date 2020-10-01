#include "SplashScreen.h"

SplashScreen::SplashScreen(std::shared_ptr<sf::RenderWindow>& window)
{
    sf::Font font;
    if(!font.loadFromFile("resources/sansation.ttf"));
    {
    }
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(30);
    pauseMessage.setPosition(120.f, 40.f);
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString("Welcome to Super-Pacman!\n\n\n\nPress ENTER to start the game\n\nUse the arrow Keys to move PacMan around \n"
                            "\n""\nESC to EXIT");

   if( !(file_image.loadFromFile("resources/pacman.jpg")) )
    {

        return;
    }

    sf::Sprite start_game(file_image);
    start_game.scale(0.4f,1.0f);

    window->draw(start_game);
    window->draw(pauseMessage);

    // Display  on screen
    window->display();


    while (window->isOpen()) {
        // Handle events
        sf::Event event;
        while (window->pollEvent(event)) {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                window->close();
                break;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter)) {
                return;
            }
        }

    }
}
