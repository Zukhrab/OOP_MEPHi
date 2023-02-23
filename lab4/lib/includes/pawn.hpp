//
//  pawn.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 08.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef pawn_hpp
#define pawn_hpp

#include "map.hpp"
#include "piece.hpp"

class Pawn: public Piece
{
    public:
        //constructors
        Pawn(enum Color _PieceColor);
    
        //getters
        enum Color getColor() override { return PieceColor; }
        enum Names getNames() override { return Names::PAWN; }
    
        //methods
        std::list<std::list<int>> visibleMoves() override
        {
            
        }
            
};

#endif /* pawn_hpp */
