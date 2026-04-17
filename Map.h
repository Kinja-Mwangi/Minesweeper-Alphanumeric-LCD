#pragma once

#include <vector>

#include "Cell.h"

enum class GameState : std::uint8_t
{
    NewGame = 0,
    Playing = 1,
    Win = 2,
    Lose = 3
};

class Map
{
    int m_Columns;
    int m_Rows;
    int m_Mines;

    std::vector<std::vector<Cell>> m_Grid;
    GameState m_State;

public:
    Map(int columns, int rows, int mines);

    GameState getState() const;
    Cell getCell(int x, int y) const;
    std::vector<Cell> getAdjacentCells(int x, int y) const;

    void reset();
    void openSquare(int x, int y);
    void flagSquare(int x, int y);

private:
    bool hasWon() const;
    bool inInBounds(int x, int y) const;

    void generateMines(int startX, int startY);
    void recursiveOpen(int startX, int startY);
};
