//
//  game.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 03.12.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <iostream>
#include "button.hpp"
#include "map.hpp"

//using namespace intrfc;

struct Player
{
    std::string name;
    Color Course;
};

class Game : public Board
{
    public:
    //
        Player Player1;
        Player Player2;
    
        sf::RenderWindow& window;
        sf::Event& event;
        std::array<std::array<intrfc::Button*, 8>, 8> interface;
        
        intrfc::Button* selectedPiece = nullptr;
        bool firstTry = false;
        bool secondTry = false;
    
        sf::Vector2<int> gotched;
        sf::Vector2<int> selected;
    
    //constructor
        Game(sf::RenderWindow& window, sf::Event& event);
    
    //methods
        bool DoMove();
        void SelectFigure();
        void Move();
        intrfc::Button* GetButton(sf::Vector2<int>& pos);
        void Draw();
        
    
        ~Game();
};

#endif /* game_hpp */
