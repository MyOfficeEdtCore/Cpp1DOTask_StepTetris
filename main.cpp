#include "board.hpp"
#include "input.hpp"
#include "render.hpp"
#include "loop.hpp"

int main(int argc, char ** argv) 
{
/*
a lot of code improvements
*/
    Board board;
    Input input;
    Render render;
    Loop loop;

    loop.Run(input, board, render);
}
