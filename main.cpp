#include "configuration.h"
#include "board.hpp"
#include "input.hpp"
#include "render.hpp"
#include "loop.hpp"

int main(int argc, char ** argv) 
{
	Configuration config;
	config.initConfiguration();

    Board board(config.board_config);
    Input input;
    Render render(config);
    Loop loop(config);

    loop.Run(input, board, render);
}
