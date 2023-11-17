#pragma once
#include "board.hpp"
#include "input.hpp"
#include "render.hpp"
#include "game.hpp"

struct Loop
{
	explicit Loop(Configuration &config)
	: config(config)
	{

	}

    void Run(Input& input, Board& board, Render& render)
    {
        Game game(board, config);
	    render.renderBoard(board);

        while(true)
        {
            const auto command = input.nextCommand();
            if(command == Command::Quit)
                break;
            if(!game.nextStep(command))
                break;
	        render.renderBoard(board);
        }
    }

	Configuration config;
};
