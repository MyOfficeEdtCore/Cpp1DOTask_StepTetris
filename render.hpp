#pragma once
#include <iostream>
#include "board.hpp"
#include "io.hpp"

struct Render
{
    IO io;

    void drawBoard(const Board& board) {
        io.clearOutput();
        for(size_t y = 0; y < BoardHeight; ++y) {
            std::cout << "|";
            for(size_t x = 0; x < BoardWidth; ++x) 
                std::cout << (board.field[BoardHeight - y - 1][x] ? "*" : " ");
            std::cout << "|" << std::endl;
            std::cout << "\r" << std::flush;
        }
        for(size_t x = 0; x < BoardWidth + 2; ++x) 
            std::cout << "=" ;
        std::cout << "\r" << std::flush;
    }
};
