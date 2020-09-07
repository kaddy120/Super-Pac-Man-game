//#include "Inputs.h"
//
//void Input::HandleEvent()
//{
//    while (window->pollEvent(event)) {
//
//        switch (event.type) {
//        case sf::Event::KeyPressed:
//            if (event.key.code == sf::Keyboard::Right)
//                MovingRight = true;
//            else if (event.key.code == sf::Keyboard::Left)
//                MovingLeft = true;
//            else if (event.key.code == sf::Keyboard::Up)
//                MovingUp = true;
//            else if (event.key.code == sf::Keyboard::Down)
//                MovingDown = true;
//            break;
//        case sf::Event::KeyReleased:
//            if (event.key.code == sf::Keyboard::Right)
//                MovingRight = false;
//            else if (event.key.code == sf::Keyboard::Left)
//                MovingLeft = false;
//            else if (event.key.code == sf::Keyboard::Up)
//                MovingUp = false;
//            else if (event.key.code == sf::Keyboard::Down)
//                MovingDown = false;
//            break;
//        case sf::Event::Closed:
//            window->close();
//            break;
//        default:
//            break;
//        }
//
//    }
//}
