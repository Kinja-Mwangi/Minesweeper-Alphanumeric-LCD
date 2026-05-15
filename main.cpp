#include "mbed.h"
#include "display/GameDisplay.h"

int main()
{
    printf("Welcome To Minesweeper!\n\n");

    GameDisplay display{20, 4, 10};
    display.run();
}
