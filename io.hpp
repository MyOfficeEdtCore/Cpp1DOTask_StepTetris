#pragma once

#ifdef WIN32
#include <conio.h>
#endif

#include <cstdlib>

class IO
{
public:
    IO() {
        system("stty -echo"); 
        system("stty raw"); 
    }

    ~IO() {
        system("stty cooked");  
        system("stty echo");   
    }

    char lastInput() {
#ifdef WIN32
        return getch();
#else
        return getchar();
#endif
    }

    void clearOutput() const {
        system("clear");
    }
};