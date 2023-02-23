//
//  button.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 18.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef button_hpp
#define button_hpp

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace intrfc
{
    class Button
    {
    public:
    
        int X, Y;
        sf::Texture texture;
        sf::Sprite sprite;
        
        Button(int Ximp, int Yimp, std::string);
        Button(const Button& b);
        void Drag(int Ximp, int Yimp);
        void Draw(sf::RenderWindow& window);
        void SetFillColor();
        void UnsetFillColor();
    };
}

#endif /* button_hpp */
