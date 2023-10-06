#pragma once

#include "command.hpp"
#include "board.hpp"
#include "moves.hpp"

struct Game
{
    Board& board;
    Block block;

    Game(Board& b)
        : board(b)
    {
        newBlockAppears();
        board.addBlock(block);
    }

    bool nextStep(Command input)
    {
        auto newBlock = newPosition(block, input);
        if (board.isCorrectMove(block, newBlock)) {
             board.removeBlock(block);
             board.addBlock(newBlock);
             block = newBlock;
        }
        removeFullLines();
        return tryNextStep(block);
    }
private:
    void newBlockAppears()
    {
        block = Block{ possibleShape[std::rand() % 3],  defaultPosition } ;
    }
 
    Block newPosition(const Block& block, Command input) {
        switch (input) {
            case Command::Rotate: return rotateBlock(block);
            case Command::MoveLeft: return moveBlockLeft(block);
            case Command::MoveRight: return moveBlockRight(block);
            case Command::Drop: return dropBlock(board, block);
        }
        return block;
    }

    void removeFullLines()
    {
        const auto isFullLine = [](const BoardLine& line)        {
            for(const auto square: line)
                if(!square)
                     return false;
            return true;
        };
        size_t shift = 0;
        for(size_t y = 0; y < BoardHeight; ++y) {
            if(isFullLine(board.field[y])) {
                ++shift; 
                continue;
            }
            if(shift > 0) 
                board.field[y - shift] = board.field[y];
        } 
    }

    bool tryNextStep(Block& block) 
    {
        auto newBlock = lowerBlock(block);
        if (board.isCorrectMove(block, newBlock) && block != newBlock) {
             board.removeBlock(block);
             board.addBlock(newBlock);
             block = newBlock;
             return true;
        }
        else {
             newBlockAppears();
             return board.addBlock(block);
        }
    }

};
