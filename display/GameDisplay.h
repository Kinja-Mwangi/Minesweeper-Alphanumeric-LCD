#pragma once

#include "TextLCD.h"
#include "../game/Map.h"
#include "../utils/Point.h"
#include "../input/Input.h"

class GameDisplay
{
    const int displayRows = 4;
    const int displayColumns = 20;

    Map m_Map;
    TextLCD m_Lcd;
    Input m_Input;
    Point m_Cursor;
    Point m_ViewPos;

    int m_GameColumns;
    int m_GameRows;

public:
    GameDisplay(int columns, int rows, int mines);
    void run();

private:
    char getCharacter(Cell cell) const;

    void handleInput();
    void lcdWrite();
    void serialWrite();
};
