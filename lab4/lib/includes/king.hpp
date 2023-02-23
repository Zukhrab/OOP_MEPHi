//
//  king.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 08.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef king_hpp
#define king_hpp

#include "piece.hpp"

class King: public Piece
{
    public:
        //constructors
        King(enum Color _PieceColor);
        
        //getters
        enum Color getColor() override { return PieceColor; }
        enum Names getNames() override { return Name; }
    
        std::list<std::list<int>> visibleMoves() override
        {
            
        }
        
    
};

#endif /* king_hpp */
