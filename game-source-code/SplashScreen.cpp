#include "SplashScreen.h"

SplashScreen::SplashScreen(std::shared_ptr<sf::RenderWindow>& window)
{
    // Create the window of the application
    // Load the text font
    sf::Font font;
    if(!font.loadFromFile("resources/sansation.ttf"));
    {
    }
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(30);
    pauseMessage.setPosition(120.f, 40.f);
    pauseMessage.setFillColor(sf::Color::Red);
    pauseMessage.setString("Welcome to Super Pacman!\n\nPress ENTER to start the game\n\n\nUse the arrows Keys to move PacMan around \n"
                            "\n""\n\nESC to EXIT");

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
        // Clear the window
        window->clear(sf::Color(0, 0, 0));

        window->draw(pauseMessage);

        // Display things on screen
        window->display();
    }
}
