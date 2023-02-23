//
//  queen.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 08.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef queen_hpp
#define queen_hpp

#include <iostream>
#include "piece.hpp"

class Queen: public Piece
{
    public:
        //constructors
        Queen(enum Color _PieceColor);
        
        //getters
        enum Color getColor() override { return PieceColor; }
        enum Names getNames() override { return Name; }
    
        std::list<std::list<int>> visibleMoves() override
        {
            
        }
        
    
};

#endif /* queen_hpp */
