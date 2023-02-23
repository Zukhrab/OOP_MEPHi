//
//  piece.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 08.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef piece_hpp
#define piece_hpp

#include <iostream>
#include <list>

enum Color
{
    BLACK,
    WHITE
};

enum Names
{
    PAWN = 1,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

class Piece
{
    protected:
        Color PieceColor;
        enum Names Name;
        bool isPressed = false;
    
    public:
    
        //constructors
        Piece() = default;
        
        //getters
        virtual enum Color getColor() = 0;
        virtual enum Names getNames() = 0;
        virtual bool& getIsPressed() { return isPressed; }
        //methods
        virtual std::list<std::list<int>> visibleMoves() = 0;
    
    
    
    
};


#endif /* piece_hpp */
