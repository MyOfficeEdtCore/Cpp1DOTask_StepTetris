#pragma once

#include "io.hpp"
#include "command.hpp"

struct Input
{
    IO io;
    Command nextCommand()
    {
        const auto input = io.lastInput();
        switch (input) {
            case 'w': return Command::Rotate;
            case 'a': return Command::MoveLeft;
            case 'd': return Command::MoveRight;
            case 's': return Command::Drop;
            case 'q': return Command::Quit;
        }
        return Command::Unknown;
    } 
};
