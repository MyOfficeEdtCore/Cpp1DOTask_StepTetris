#pragma once

#include "configuration.h"
#include "command.hpp"
#include "board.hpp"
#include "moves.hpp"

class Game
{
protected:
	const Block::BlockPosition defaultPosition;

	Board& board;
	Block block;

public:
    Game(Board& b, Configuration& config)
    : board(b)
	, block(config.block_config)
	, remove_logic(config.remove_lines_logic)
	, defaultPosition({config.board_config.height, config.board_config.width/2 - config.block_config.height/2})
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
             block.field = newBlock.field;
             block.upperLeft = newBlock.upperLeft;
        }

		switch (remove_logic)
		{
		case Configuration::rllFullLines:
			removeFullLines();
			break;
		case Configuration::rllThreeFullLines:
			removeThreeFullLines();
			break;
		case Configuration::rllNotRemove:
			removeNotRemove();
			break;
		case Configuration::rllNinetyPercent:
			removeNinetyPercent();
			break;
		}

        return tryNextStep(block);
    }

private:
    void newBlockAppears()
    {
        block.field = block.possibleShape[std::rand() % 3];
		block.upperLeft = defaultPosition;
    }
 
    Block newPosition(const Block& block, Command input) {
        switch (input) {
            case Command::Rotate:
				return rotateBlock(block);
            case Command::MoveLeft:
	            return moveBlockLeft(block);
            case Command::MoveRight:
	            return moveBlockRight(block);
            case Command::Drop:
	            return dropBlock(board, block);
        }
        return block;
    }

    void removeFullLines()
    {
        const auto isFullLine = [](Board::BoardLine& line) {
            for(const auto square: line)
                if(!square)
                     return false;
            return true;
        };
        size_t shift = 0;
        for(size_t y = 0; y < board.BoardHeight; ++y) {
            if(isFullLine(board.field[y])) {
                ++shift; 
                continue;
            }
            if(shift > 0) 
                board.field[y - shift] = board.field[y];
        } 
    }
	void removeThreeFullLines() {};
	void removeNotRemove() {};
	void removeNinetyPercent() {};

    bool tryNextStep(Block& block)
    {
        auto newBlock = lowerBlock(block);
        if (board.isCorrectMove(block, newBlock) && block != newBlock) {
             board.removeBlock(block);
             board.addBlock(newBlock);
	        block.field = newBlock.field;
	        block.upperLeft = newBlock.upperLeft;
             return true;
        }
        else {
             newBlockAppears();
             return board.addBlock(block);
        }
    }

	Configuration::RemoveLinesLogic remove_logic;
};
