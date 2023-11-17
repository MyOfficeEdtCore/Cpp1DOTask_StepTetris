#pragma once
#include <iostream>
#include "configuration.h"
#include "board.hpp"
#include "io.hpp"

class Render
{
public:
	explicit Render(Configuration &config)
	: flag_write_file(config.render_config.flag_write_file)
	, flag_send_net(config.render_config.flag_send_net)
	{
		rendered_board.reserve(config.board_config.height * config.board_config.width);
	}

	void renderBoard(const Board& board)
	{
		rendered_board.clear();
		for (auto y = 0; y < board.BoardHeight; ++y)
		{
			rendered_board += "|";
			for(size_t x = 0; x < board.BoardWidth; ++x)
				rendered_board += (board.field[board.BoardHeight - y - 1][x] ? "*" : " ");
			rendered_board += "|";
			rendered_board += "\n";
		}
		for(size_t x = 0; x < board.BoardWidth + 2; ++x)
			rendered_board += "=";

		drawBoard();
		if (flag_write_file)
			writeFile();
		if (flag_send_net)
			sendNet();
	}

protected:
	void drawBoard() {
		io.clearOutput();
		for (auto & c : rendered_board)
		{
			std::cout << c;
			if (c == '\n')
				std::cout << "\r" << std::flush;
		}
		std::cout << "\r" << std::flush;
	}

	void writeFile() {};
	void sendNet() {};


    IO io;

	std::string rendered_board;
	bool flag_write_file;
	bool flag_send_net;
};
