//
//  bishop.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 17.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef bishop_hpp
#define bishop_hpp

#include "piece.hpp"

class Bishop: public Piece
{
    public:
        //constructors
        Bishop(enum Color _PieceColor);
        
        //getters
        enum Color getColor() override { return PieceColor; }
        enum Names getNames() override { return Name; }
    
        std::list<std::list<int>> visibleMoves() override
        {
            
        }
        
    
};

#endif /* bishop_hpp */
