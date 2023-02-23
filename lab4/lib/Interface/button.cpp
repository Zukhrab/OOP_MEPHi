//
//  button.cpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 18.11.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#include "button.hpp"

namespace intrfc
{
    Button::Button(int Ximp, int Yimp, std::string Limp): X(Ximp), Y(Yimp)
    {
        texture.loadFromFile(Limp);
        sprite.setTexture(texture); sprite.setPosition(X, Y);
    }
    
    Button::Button(const Button& b)
    {
        X = b.X;
        Y = b.Y;
        sprite = b.sprite;
        texture = b.texture;
    }

    void Button::Drag(int Ximp, int Yimp)
    {
        sprite.setPosition(Ximp, Yimp);
        UnsetFillColor();
    }

    void Button::Draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }

    void Button::SetFillColor()
    {
        sprite.setColor(sf::Color(170,170,170));
    }

    void Button::UnsetFillColor()
    {
        sprite.setColor(sf::Color(255,255,255));
    }
}
