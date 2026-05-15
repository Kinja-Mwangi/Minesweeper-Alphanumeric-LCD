#include "GameDisplay.h"
#include "Input.h"
#include "Map.h"

int clamp(int value, int high, int low)
{
    if (value > high) return high;
    if (value < low) return low;
    return value;
}

GameDisplay::GameDisplay(int columns, int rows, int mines) :
    m_Map(columns, rows, mines), m_Lcd(D0, D1, D2, D3, D4, D5, TextLCD::LCD20x4),
    m_Input(D10, D11, D12, D13, D8, D9)
{
    m_GameColumns = columns;
    m_GameRows = rows;
}

void GameDisplay::run()
{
    while (m_Map.getState() == GameState::Playing || m_Map.getState() == GameState::NewGame)
    {
        handleInput();
        lcdWrite();
        serialWrite();
    }

    GameState endState = m_Map.getState();

    if (endState == GameState::Win)
    {
        printf("Game won\n");
    }
    else if (endState == GameState::Lose)
    {
        printf("Game lost\n");
    }
}

void GameDisplay::handleInput()
{
    // TODO add logic for mine/flag buttons

    if (m_Input.isButtonDown(InputName::Open))
    {
        Cell square = m_Map.getCell(m_Cursor.x, m_Cursor.y);

        if (!square.open)
        {
            m_Map.openSquare(m_Cursor);
        }
        else if (square.adjacentMines > 0)
        {
            auto adjacents = m_Map.getAdjacentPoints(m_Cursor);
            int flagCount = 0;

            for (auto& point : adjacents)
            {
                if (m_Map.getCell(m_Cursor.x, m_Cursor.y).flagged) flagCount++;
            }

            if (flagCount >= square.adjacentMines)
            {
                for (auto& point : adjacents)
                {
                    m_Map.openSquare(point);
                }
            }
        }

        return; // Do not move the cursor if movement buttons are held
    }

    if (m_Input.isButtonDown(InputName::Flag))
    {
        m_Map.flagSquare(m_Cursor);
        return; // Do not move the cursor if movement buttons are held
    }

    auto direction = Point();
    if (m_Input.isButtonDown(InputName::Up)) direction.x--;
    if (m_Input.isButtonDown(InputName::Down)) direction.x++;
    if (m_Input.isButtonDown(InputName::Left)) direction.y--;
    if (m_Input.isButtonDown(InputName::Right)) direction.y++;

    auto newCursor = Point();
    newCursor.x = clamp(m_Cursor.x + direction.x, 0, displayColumns);
    newCursor.y = clamp(m_Cursor.y + direction.y, 0, displayRows);

    if (newCursor.x >= m_ViewPos.x + displayColumns)
        m_ViewPos.x++;
    else if (newCursor.x < m_ViewPos.x)
        m_ViewPos.x--;

    if (newCursor.y >= m_ViewPos.y + displayColumns)
        m_ViewPos.y++;
    else if (newCursor.y < m_ViewPos.y)
        m_ViewPos.y--;
}

void GameDisplay::lcdWrite()
{
    for (int y = 0; y < displayRows; y++)
    {
        m_Lcd.locate(0, y);
        char buffer[displayColumns];

        for (int x = 0; x < displayColumns; x++)
        {
            // 0xFF = black box
            buffer[x] = Point(x, y) == m_Cursor ? 0xFF : getCharacter(m_Map.getCell(x + m_ViewPos.x, y + m_ViewPos.y));
        }

        m_Lcd.printf("%s", buffer);
    }
}

// TODO use the buffer trick with this version
void GameDisplay::serialWrite()
{
    for (int i = 0; i < m_GameColumns; i++)
    {
        for (int j = 0; j < m_GameRows; j++)
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

char GameDisplay::getCharacter(Cell cell) const
{
    if (cell.open)
    {
        return cell.mine ? 'X' : static_cast<char>(cell.adjacentMines);
    }
    else if (cell.flagged)
    {
        return 'F';
    }
    else
    {
        return '+';
    }
}
