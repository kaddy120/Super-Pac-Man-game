#include "GameEndScreen.h"

GameEndScreen::GameEndScreen(const std::shared_ptr<sf::RenderWindow>& window, const sf::Text& text):
    Window_(window),
	Text(text)
{}

void GameEndScreen::Render(const unsigned int& level, const std::string& message)
{
    while (Window_->isOpen()) {
        // Handle events
        sf::Event event;
        while (Window_->pollEvent(event)) {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                Window_->close();
                break;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter)) {
                return;
            }
        }
        // Clear the window
        Window_->clear(sf::Color(0, 0, 0));

        Window_->draw(Text);

        // Display things on screen
        Window_->display();
    }
}
