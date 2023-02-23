//
//  map.cpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 29.10.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#include "map.hpp"

//constructors
Board::Board()
{
    std::cout << "Board constructor" << std::endl;
    Stack.push("Start");
    ClockWhite1 = 182;
    ClockBlack2 = 180;
    Current_Time = 0;
    
    for (int y = 0; y < 8; y++)
        for(int x = 0; x < 8; x++)
        {
            if((y == 0 || y == 7) && (x == 0 || x == 7))
            {
                if(y == 0)
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Rook(BLACK);
                }
                else
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Rook(WHITE);
                }
            }
            if((y == 0 || y == 7) && (x == 1 || x == 6))
            {
                if(y == 0)
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Knight(BLACK);
                }
                else
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Knight(WHITE);
                }
            }
            if((y == 0 || y == 7) && (x == 2 || x == 5))
            {
                if(y == 0)
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Bishop(BLACK);
                }
                else
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Bishop(WHITE);
                }
            }
            if((y == 0 || y == 7) && (x == 3))
            {
                if(y == 0)
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Queen(BLACK);
                }
                else
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Queen(WHITE);
                }
            }
            if((y == 0 || y == 7) && (x == 4))
            {
                if(y == 0)
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new King(BLACK);
                }
                else
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new King(WHITE);
                }
            }
            if((y == 1 || y == 6))
            {
                if(y == 1)
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Pawn(BLACK);
                }
                else
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = new Pawn(WHITE);
                }
            }
            if((y == 2 || y == 5))
            {
                if(y == 2)
                {
                    board.at(y).at(x).UABLACK = YES;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = nullptr;
                }
                else
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = YES;
                    board.at(y).at(x).PP = nullptr;
                }
            }
            if((y == 3 || y == 4))
            {
                if(y == 3)
                {
                    board.at(y).at(x).UABLACK = YES;
                    board.at(y).at(x).UAWHITE = NO;
                    board.at(y).at(x).PP = nullptr;
                }
                else
                {
                    board.at(y).at(x).UABLACK = NO;
                    board.at(y).at(x).UAWHITE = YES;
                    board.at(y).at(x).PP = nullptr;
                }
            }
        }
}

//getters
std::stack<std::string> Board::getStack() const { return Stack; }
int Board::getClock1() const { return ClockWhite1; }
int Board::getClock2() const { return ClockBlack2; }
int Board::getCurrent_Time() const { return Current_Time; }

//methods
void Board::Time()
{
    while(1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Current_Time++;
        ClockWhite1 -= Current_Time;
        Current_Time = 0;
        std::cout << ClockWhite1 << std:: endl;
    }
}
void Board::ShowHistory()
{
    while(Stack.size())
    {
        std::cout << Stack.top() << std::endl;
        Stack.pop();
    }
}

void Board::ShowBoard()
{
    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
            if (board.at(y).at(x).PP != nullptr)
                std::cout << board.at(y).at(x).PP->getNames() << ' ';
        std::cout << std::endl;
    }
}

void Board::ShowBoardWhiteUA()
{
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
            std::cout << board.at(x).at(y).UAWHITE << ' ';
        std::cout << std::endl;
    }
}

void Board::ShowBoardBlackUA()
{
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
            std::cout << board.at(x).at(y).UABLACK << ' ';
        std::cout << std::endl;
    }
}

void Board::AddStackString(int name, int fromX, int fromY, int toX, int toY)
{
    std::string result = "";
    
    switch(name)
    {
        case (1):
            result += "P:";
            break;
        case (2):
            result += "R:";
            break;
        case (3):
            result += "K:";
            break;
        case (4):
            result += "B:";
            break;
        case (5):
            result += "Q:";
            break;
        case (6):
            result += "M:";
            break;
        default:
            break;
    }
    
    switch(fromY)
    {
        case (0):
            result += 'a';
            break;
        case (1):
            result += 'b';
            break;
        case (2):
            result += 'c';
            break;
        case (3):
            result += 'd';
            break;
        case (4):
            result += 'e';
            break;
        case (5):
            result += 'f';
            break;
        case (6):
            result += 'g';
            break;
        case (7):
            result += 'h';
            break;
        default:
            break;
    }
    result += std::to_string(8 - fromX);
    result += '-';
    
    switch(toY)
    {
        case (0):
            result += 'a';
            break;
        case (1):
            result += 'b';
            break;
        case (2):
            result += 'c';
            break;
        case (3):
            result += 'd';
            break;
        case (4):
            result += 'e';
            break;
        case (5):
            result += 'f';
            break;
        case (6):
            result += 'g';
            break;
        case (7):
            result += 'h';
            break;
        default:
            break;
    }
    result += std::to_string(8 - toY);
    
    Stack.push(result);
}

Cage Board::GetFigure(sf::Vector2<int>& coordinates)
{
    Cage empty;
    if(board.at(coordinates.y).at(coordinates.x).PP == nullptr)
    {
//        coordinates.x = -1;
//        coordinates.y = -1;
        return empty;
    }
    
    return board.at(coordinates.y).at(coordinates.x);
}

sf::Vector2<int> Board::PieceRecognation(sf::Vector2<int> figure)
{
    sf::Vector2<int> temp;
    temp.x = board.at(figure.y).at(figure.x).PP->getColor();
    temp.y = board.at(figure.y).at(figure.x).PP->getNames();
    return temp;
}

Board::~Board()
{
    for(int x = 0; x < 8; x++)
        for(int y = 0; y < 8; y++)
        {
            board.at(x).at(y).UABLACK = NO;
            board.at(x).at(y).UAWHITE = NO;
        }
}
