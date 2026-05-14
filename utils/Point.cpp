#include "Point.h"

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int xPos, int yPos)
{
    x = xPos;
    y = yPos;
}

Point Point::operator+(Point other) const
{
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(Point other) const
{
    return Point(x - other.x, y - other.y);
}

bool Point::operator==(Point other) const
{
    return x == other.x && y == other.y;
}

bool Point::operator!=(Point other) const
{
    return !(*this == other);
}
