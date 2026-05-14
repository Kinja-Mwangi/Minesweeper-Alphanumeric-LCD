#include "Input.h"

Input::Input(PinName up, PinName down, PinName left, PinName right, PinName open, PinName flag) :
    m_Up(up, PullDown), m_Down(down, PullDown), m_Left(left, PullDown), m_Right(right, PullDown), m_Open(open, PullDown), m_Flag(flag, PullDown) { }

bool Input::isButtonDown(InputName name)
{

    switch (name)
    {
    case InputName::Up:
        return m_Up == true;
    case InputName::Down:
        return m_Down == true;
    case InputName::Left:
        return m_Left == true;
    case InputName::Right:
        return m_Right == true;
    case InputName::Open:
        return m_Open == true;
    case InputName::Flag:
        return m_Flag == true;
    default:
        return false;
    }
}
