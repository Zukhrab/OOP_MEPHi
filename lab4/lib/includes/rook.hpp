//
//  rook.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 17.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef rook_hpp
#define rook_hpp

#include "piece.hpp"

class Rook: public Piece
{
    public:
        //constructors
        Rook(enum Color _PieceColor);
        
        //getters
        enum Color getColor() override { return PieceColor; }
        enum Names getNames() override { return Name; }
        
        std::list<std::list<int>> visibleMoves() override
        {
            
        }
    
};

#endif /* rook_hpp */
