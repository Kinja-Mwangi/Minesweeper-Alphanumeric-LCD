#include "Map.h"

Point::Point(int xPos, int yPos)
{
    x = xPos;
    y = yPos;
}

Point::operator+(Point other) const
{
    return Point(x + other.x, y + other.y);
}

// To be used by the recursiveOpen function soon
constexpr Point* deltas = {
    Point(-1, -1), // Top left
    Point( 0, -1), // Top centre
    Point( 1, -1), // Top right
    Point( 1,  0), // Middle right
    Point( 1,  1), // Bottom right
    Point( 0,  1), // Bottom centre
    Point(-1,  1), // Bottom left
    Point(-1,  0), // Middle left
};

Map::Map(int columns, int rows, int mines)
{
    m_Columns = columns;
    m_Rows = rows;
    m_Mines = mines;

    m_Grid.resize(columns);

    for(auto& column : m_Grid)
    {
        column.resize(rows);
    }
}

void Map::getState() const
{
    return m_State;
}

void Map::getCell(int x, int y) const
{
    return m_Grid[x, y];
}

std::vector<Cell> getAdjacentCells(int x, int y) const
{
    
}

void Map::reset()
{
    for (auto& column : m_Grid)
    {
        for (auto& cell : column)
        {
            cell = Cell();
        }
    }

    m_State = GameState::NewGame;
}

void Map::openSquare(int x, int y)
{

}

void Map::openSquare(int x, int y)
{

}

bool Map::hasWon() const;
{

}

bool Map::isInBounds(int x, int y) const;
{

}

void Map::generateMines(int startX, int startY);
{

}

void Map::recursiveOpen(int startX, int startY);
{

}
