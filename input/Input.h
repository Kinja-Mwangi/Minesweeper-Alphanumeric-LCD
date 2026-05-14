#pragma once

#include "mbed.h"
#include <cstdint>

enum class InputName : std::uint8_t
{
    Up = 0,
    Down = 1,
    Left = 2,
    Right = 3,
    Open = 4,
    Flag = 5
};

class Input
{   
    DigitalIn m_Up;
    DigitalIn m_Down;
    DigitalIn m_Left;
    DigitalIn m_Right;
    
    DigitalIn m_Open;
    DigitalIn m_Flag;

public:
    Input(PinName up, PinName down, PinName left, PinName right, PinName open, PinName flag);
    bool isButtonDown(InputName name);
};
