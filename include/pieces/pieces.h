#pragma once

#include<iostream>

class Piece
{
    public:
        Piece();
        std::string pieceName;
        virtual void comment()
        {
            std::cout<<pieceName<<" added";
        }
};

