#pragma once
#include "block.hpp"

static constexpr size_t BoardHeight = 25;
static constexpr size_t BoardWidth = 10; 
using BoardLine = std::array<bool, BoardWidth>;
using BoardField = std::array<BoardLine, BoardHeight>;


static constexpr BlockPosition defaultPosition = {BoardHeight, BoardWidth/2 - BlockHeight/2};

struct Board {
    BoardField field;

    Board()
    {
        for(size_t y = 0; y < BoardHeight; ++y)    
            field[y].fill({});
    } 

    bool isCorrectMove(const Block& block, const Block& newBlock); 
    void removeBlock(const Block& block);
    bool addBlock(const Block& block);
};

bool Board::isCorrectMove(const Block& block, const Block& newBlock) {
    removeBlock(block);
    for(int x = 0; x < BlockWidth; ++x) 
        for(int y = 0; y < BlockHeight; ++y) 
            if(newBlock.field[x][y] == true) {
                if( newBlock.upperLeft.first - y <= 0 ||
                    newBlock.upperLeft.second + x < 0 ||
                    newBlock.upperLeft.second + x > BoardWidth - 1  ||
                    field[newBlock.upperLeft.first - y - 1][newBlock.upperLeft.second + x]){
                  addBlock(block);
                  return false;  
                }
            }
    addBlock(block);
    return true;
}

void Board::removeBlock(const Block& block) {
    for(size_t x = 0; x < BlockWidth; ++x) 
        for(size_t y = 0; y < BlockHeight; ++y) 
            if(block.field[x][y] == true)
                field[block.upperLeft.first - y - 1][block.upperLeft.second + x] = false;
}

bool Board::addBlock(const Block& block) {
    for(size_t x = 0; x < BlockWidth; ++x)
        for(size_t y = 0; y < BlockHeight; ++y) 
            if(block.field[x][y] == true) {
                bool& square = field[block.upperLeft.first - y - 1][block.upperLeft.second + x];
                if(square)
                     return false;
                square = true;
            }
    return true;
}


