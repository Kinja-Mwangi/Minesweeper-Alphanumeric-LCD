#pragma once

#include "TextLCD.h"
#include "../game/Map.h"
#include "../utils/Point.h"

class GameDisplay
{
    Map m_Map;
    TextLCD m_Lcd;
    Point m_Cursor;

    int m_Columns;
    int m_Rows;

public:
    GameDisplay(int columns, int rows, int mines);

private:
    void lcdWrite();
    void serialWrite();
};
