#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "map.hpp"
#include "array.hpp"
#include <stdexcept>
#include "game.hpp"
#include "button.hpp"

#include "ResourcePath.hpp"

// Start.game.ShowHistory(); показывает что находится в стек
// Start.game.Time(); // простой таймер - установлено 180
// Start.game.getStack(); // возвращает стек; историю игры
// std::cout << Start.game.getClock1() << std::endl; возвращает время первого юзера
// std::cout << Start.game.getClock2() << std::endl; возвращает время второго юзера
// std::cout << Start.game.getCurrent_Time() << std::endl; возвращает текущее время юзера

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 1024), "Chess");
    sf::Event event;
    Game g(window, event);
    
    
    // B A C K G R O U N D //
    sf::Texture ChessMap; ChessMap.loadFromFile("/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Boards/Board_Classic_2_JPEG.jpg");
    sf::Sprite _ChessMapSp_; _ChessMapSp_.setTexture(ChessMap); _ChessMapSp_.setPosition(0, 0);
    // B A C K G R O U N D //
    
    while (window.isOpen())
    {
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left){
                    g.SelectFigure();
                    g.DoMove();
                }
        
//        std::cout << sf::Mouse::getPosition(window).x << ' ';
//        std::cout << sf::Mouse::getPosition(window).y << std::endl;
        
        
        
        
        
        window.clear();
        g.ShowBoard();
        window.draw(_ChessMapSp_);
        g.Draw();
        window.display();
    }
    
    return 0;
};

