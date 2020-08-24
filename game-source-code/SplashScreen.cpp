#include "SplashScreen.h"

SplashScreen::SplashScreen(std::shared_ptr<sf::RenderWindow>& window)
{
    // Create the window of the application
    window->setVerticalSyncEnabled(true);
    // Load the text font
    sf::Font font;
    font.loadFromFile("resources/sansation.ttf");
    //if(!font.loadFromFile("resources/sansation.ttf"))
    //return EXIT_FAILURE;
    // Initialize the pause message
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(30);
    pauseMessage.setPosition(120.f, 40.f);
    pauseMessage.setFillColor(sf::Color::Red);
    pauseMessage.setString("Welcome to Duel Invaders!\nPress ENTER to start the game\n\nFor the top player: \n"
        "Press Left Key to move to the left\nPress Right Key to move to the right\n"
        "Press down key to shoot\n\n\nFor bottom player : \n"
        "Press Z Key to move to the left\nPress C Key to move to the right\n"
        "Press space key to shoot\n\nESC to EXIT");


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
                    // Space key pressed: play
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter))) {
               // GameScreen play;
                //window.close();
                break;
            }
        }
        // Clear the window
        window->clear(sf::Color(50, 200, 50));

        window->draw(pauseMessage);

        // Display things on screen
        window->display();
    }
}
