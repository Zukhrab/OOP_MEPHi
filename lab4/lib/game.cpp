//
//  game.cpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 03.12.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#include "game.hpp"

//constructor
Game::Game(sf::RenderWindow& window, sf::Event& event): window(window), event(event)
{
    Player1.name = "User1";
    Player1.Course = WHITE;
    Player2.name = "User2";
    Player2.Course = BLACK;
    
    // B U T T T O N S -- P I E C E S //
    interface.at(0).at(0) = new intrfc::Button(0, 0, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_10.png");
    interface.at(0).at(1) = new intrfc::Button(128, 0, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_09.png");
    interface.at(0).at(2) = new intrfc::Button(256, 0, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_08.png");
    interface.at(0).at(3) = new intrfc::Button(384, 0, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_11.png");
    interface.at(0).at(4) = new intrfc::Button(512, 0, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_12.png");
    interface.at(0).at(5) = new intrfc::Button(640, 0, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_08.png");
    interface.at(0).at(6) = new intrfc::Button(768, 0, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_09.png");
    interface.at(0).at(7) = new intrfc::Button(896, 0, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_10.png");

    interface.at(1).at(0) = new intrfc::Button(0, 128, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_07.png");
    interface.at(1).at(1) = new intrfc::Button(128, 128, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_07.png");
    interface.at(1).at(2) = new intrfc::Button(256, 128, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_07.png");
    interface.at(1).at(3) = new intrfc::Button(384, 128, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_07.png");
    interface.at(1).at(4) = new intrfc::Button(512, 128, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_07.png");
    interface.at(1).at(5) = new intrfc::Button(640, 128, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_07.png");
    interface.at(1).at(6) = new intrfc::Button(768, 128, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_07.png");
    interface.at(1).at(7) = new intrfc::Button(896, 128, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_07.png");

    
    interface.at(6).at(0) = new intrfc::Button(0, 768, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_01.png");
    interface.at(6).at(1) = new intrfc::Button(128, 768, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_01.png");
    interface.at(6).at(2) = new intrfc::Button(256, 768, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_01.png");
    interface.at(6).at(3) = new intrfc::Button(384, 768, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_01.png");
    interface.at(6).at(4) = new intrfc::Button(512, 768, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_01.png");
    interface.at(6).at(5) = new intrfc::Button(640, 768, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_01.png");
    interface.at(6).at(6) = new intrfc::Button(768, 768, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_01.png");
    interface.at(6).at(7) = new intrfc::Button(896, 768, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_01.png");
    
    interface.at(7).at(0) = new intrfc::Button(0, 896, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_04.png");
    interface.at(7).at(1) = new intrfc::Button(128, 896, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsD_03.png");
    interface.at(7).at(2) = new intrfc::Button(256, 896, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsD_02.png");
    interface.at(7).at(3) = new intrfc::Button(384, 896, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsD_05.png");
    interface.at(7).at(4) = new intrfc::Button(512, 896, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsD_06.png");
    interface.at(7).at(5) = new intrfc::Button(640, 896, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsD_02.png");
    interface.at(7).at(6) = new intrfc::Button(768, 896, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsD_03.png");
    interface.at(7).at(7) = new intrfc::Button(896, 896, "/Users/zukhrabasakhanov/Documents/Lab 4/Lab 4/Assets/Pieces/06_realOpponentsE_04.png");
    // B U T T T O N S -- P I E C E S //
    for(int i = 2; i < 6; i++)
        for(int j = 0; j < 8; j++)
            interface.at(i).at(j) = nullptr;
}


//methods
sf::Vector2<int> PressingCoordinates(sf::RenderWindow& window)              // возвращает координаты в виде координат матрицы:
{                                                                           // если нажали не на фигуру то возвращает -1, -1;
    sf::Vector2<int> null(-1, -1);
    
    if(((sf::Mouse::getPosition(window).x <= 0) || (sf::Mouse::getPosition(window).x >= 1024) ||
        (sf::Mouse::getPosition(window).y <= 0) || (sf::Mouse::getPosition(window).y >= 1024)))
        return null;
    
    null.x = sf::Mouse::getPosition(window).x / 128;
    null.y = sf::Mouse::getPosition(window).y / 128;
    
    return null;
}


void Game::SelectFigure()
{
    if (selectedPiece)
        return;
    if(event.mouseButton.button == sf::Mouse::Left)
    {
        gotched = PressingCoordinates(window);
        if (!(GetFigure(gotched).PP))
            return;
        
        selectedPiece = GetButton(gotched);
        selectedPiece->SetFillColor();
        firstTry = true;
        return;
    }
}

intrfc::Button* Game::GetButton(sf::Vector2<int>& pos)
{
    return interface.at(pos.y).at(pos.x);
}

void Game::Move()
{
    if (selected != gotched){
        interface.at(selected.y).at(selected.x) = selectedPiece;
        interface.at(gotched.y).at(gotched.x) = nullptr;
        
//        board.at(selected.y).at(selected.x) = board.at(gotched.y).at(gotched.x);
//        board.at(gotched.y).at(gotched.x) = Cage{};
    }
}

bool Game::DoMove()
{
    if (firstTry)
    {
        firstTry = false;
        return false;
    }
    
    if (event.mouseButton.button == sf::Mouse::Left)
    {
        selected = PressingCoordinates(window);
        if((selected.x == -1 && selected.y == -1) || (selected == gotched))
            return false;
        
        Cage selectedFigure = GetFigure(selected), gotchedFigure = GetFigure(gotched);
        if (selectedPiece && selectedFigure.PP && (selectedFigure.PP->getColor() == gotchedFigure.PP->getColor()))
        {
            selectedPiece->UnsetFillColor();
            selectedPiece = GetButton(selected);
            selectedPiece->SetFillColor();
            selected = sf::Vector2<int>(-1, -1);
            firstTry = true;
            return false;
        }
        
        if (selectedPiece)
        {
            selectedPiece->Drag(selected.x * 128, selected.y * 128);
            Move();
            selectedPiece = nullptr;
        }
        return true;
    }
    return false;
}

void Game::Draw()
{
    for (int y = 0; y < 8; y++)
        for(int x = 0; x < 8; x++)
        {
            if (interface.at(y).at(x) != nullptr)
                interface.at(y).at(x)->Draw(window);
        }
}


//destructor
Game::~Game()
{
    for(int i = 0; i < 8; i++) delete interface.at(0).at(i);
    for(int i = 0; i < 8; i++) delete interface.at(1).at(i);
    for(int i = 0; i < 8; i++) delete interface.at(6).at(i);
    for(int i = 0; i < 8; i++) delete interface.at(7).at(i);
}
