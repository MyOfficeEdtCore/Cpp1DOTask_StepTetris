#pragma once
#include "board.hpp"
#include "input.hpp"
#include "render.hpp"
#include "game.hpp"

struct Loop
{
    void Run(Input& input, Board& board, Render& render)
    {
        Game game(board);
        render.drawBoard(board);

        while(true)
        {
            const auto command = input.nextCommand();
            if(command == Command::Quit)
                break;
            if(!game.nextStep(command))
                break;
            render.drawBoard(board);
        }
    }
};
