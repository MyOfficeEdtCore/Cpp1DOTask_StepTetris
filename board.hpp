#pragma once
#include "block.hpp"

class Board {
public:
	const size_t BoardHeight;
	const size_t BoardWidth;

	using BoardLine = std::vector<int>;
	using BoardField = std::vector<BoardLine>;

	BoardField field;

	Board(Configuration::BoardConfig &board_config)
	: BoardHeight(board_config.height)
	, BoardWidth(board_config.width)
	{
		field.resize(BoardHeight);
		for (auto i = 0; i < BoardHeight; i++)
		{
			field[i].resize(BoardWidth);
		}
	}

	bool isCorrectMove(const Block& block, const Block& newBlock);
	void removeBlock(const Block& block);
	bool addBlock(const Block& block);
};

bool Board::isCorrectMove(const Block& block, const Block& newBlock) {
	removeBlock(block);
	for(int x = 0; x < block.BlockWidth; ++x)
		for(int y = 0; y < block.BlockHeight; ++y)
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
	for(size_t x = 0; x < block.BlockWidth; ++x)
		for(size_t y = 0; y < block.BlockHeight; ++y)
			if(block.field[x][y] == true)
				field[block.upperLeft.first - y - 1][block.upperLeft.second + x] = false;
}

bool Board::addBlock(const Block& block) {
	for(size_t x = 0; x < block.BlockWidth; ++x)
		for(size_t y = 0; y < block.BlockHeight; ++y)
			if(block.field[x][y] == true) {
				int& square = field[block.upperLeft.first - y - 1][block.upperLeft.second + x];
				if(square)
					return false;
				square = true;
			}
	return true;
}
