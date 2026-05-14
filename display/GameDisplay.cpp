#include "GameDisplay.h"

GameDisplay::GameDisplay(int columns, int rows, int mines) :
    m_Map(columns, rows, mines), m_Lcd(D0, D1, D2, D3, D4, D5, TextLCD::LCD20x4)
{
    m_Columns = columns;
    m_Rows = rows;
}

void GameDisplay::lcdWrite()
{
    for (int x = 0; x < m_Columns; x++)
    {
        m_Lcd.locate(0, 0); // Finish this
    }
}

void GameDisplay::serialWrite()
{
    for (int i = 0; i < m_Columns; i++)
    {
        for (int j = 0; j < m_Rows; j++)
        {
            Cell cell = m_Map.getCell(i, j);

            if (Point(i, j) == m_Cursor)
            {
                printf("@");
            }
            else if (cell.open)
            {
                cell.mine ? printf("X") : printf("%i", cell.adjacentMines);
            }
            else if (cell.flagged)
            {
                printf("F");
            }
            else
            {
                printf("+");
            }
        }

        printf("\n");
    }

    printf("\n\n");
}
