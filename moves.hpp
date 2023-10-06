#pragma once

#include "board.hpp"
#include "block.hpp"

Block lowerBlock(const Block& block) {
    return Block{block.field, { block.upperLeft.first - 1, block.upperLeft.second}};
}

Block moveBlockLeft(const Block& block) {
    return Block{block.field, { block.upperLeft.first, block.upperLeft.second - 1}};
}

Block moveBlockRight(const Block& block) {
    return Block{block.field, { block.upperLeft.first, block.upperLeft.second + 1}};
}

Block rotateBlock(const Block& block) {
    Block newBlock = block;
    for(size_t x = 0; x < BlockWidth; ++x) 
        for(size_t y = 0; y < BlockHeight; ++y) 
            newBlock.field[x][y] = block.field[y][x];
    return newBlock;
}

Block dropBlock(Board& board, const Block& block) {
    Block newBlock = block;
    while(board.isCorrectMove(block, newBlock)) 
        --newBlock.upperLeft.first;
    ++newBlock.upperLeft.first;
    return newBlock;
}


