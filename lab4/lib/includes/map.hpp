//
//  map.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 29.10.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
#include <array>
#include <stack>
#include <memory>
#include <unistd.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "piece.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"

enum UnderAttack
{
    NO,
    YES
};

struct Cage
{
    UnderAttack UABLACK;
    UnderAttack UAWHITE;
    Piece* PP = nullptr;
};

class Board
{
    protected:
        std::stack<std::string> Stack;
        std::array<std::array<Cage, 8>, 8> board;
        int ClockWhite1;
        int ClockBlack2;
        int Current_Time;
    
    public:
        //constructors
        Board();
    
        //getters
        std::stack<std::string> getStack() const;
        int getClock1() const;
        int getClock2() const;
        int getCurrent_Time() const;
    
        //methods
        void Time();
        void ShowBoard();
        void ShowBoardWhiteUA();
        void ShowBoardBlackUA();
        void ShowHistory();
        void AddStackString(int name, int fromX, int fromY, int toX, int toY);
        void TryUse();
    
        Cage GetFigure(sf::Vector2<int>& coordinates);
        sf::Vector2<int> PieceRecognation(sf::Vector2<int> figure);
        bool DoMove();
    
        ~Board();
};
#endif /* map_hpp */
