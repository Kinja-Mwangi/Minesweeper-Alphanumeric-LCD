#pragma once

struct Point
{
    int x,
    int y,

    Point(int xPos, int yPos);

    Point operator+(Point other) const;
};


struct Cell
{
    bool mine = false;
    bool open = false;
    bool flagged = false;
    int adjacentMines = 0;
};
