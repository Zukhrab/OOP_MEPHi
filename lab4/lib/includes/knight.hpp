//
//  knight.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 17.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef knight_hpp
#define knight_hpp

#include "piece.hpp"

class Knight: public Piece
{
    public:
        //constructors
        Knight(enum Color _PieceColor);
    
        //getters
        enum Color getColor() override { return PieceColor; }
        enum Names getNames() override { return Name; }
    
        virtual std::list<std::list<int>> visibleMoves() override 
        {
            
        }
        
    
};

#endif /* knight_hpp */
