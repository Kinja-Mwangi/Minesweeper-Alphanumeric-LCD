#pragma once

struct Point
{
    int x;
    int y;

    Point();
    Point(int xPos, int yPos);

    Point operator+(Point other) const;
    Point operator-(Point other) const;
    bool operator==(Point other) const;
    bool operator!=(Point other) const;
};
