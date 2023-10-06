#include "board.hpp"
#include "input.hpp"
#include "render.hpp"
#include "loop.hpp"

int main(int argc, char ** argv) 
{
    Board board;
    Input input;
    Render render;
    Loop loop;

    loop.Run(input, board, render);
}
