#pragma once

#include <cstdint>
#include <iostream>

class CTerminalHelper
{
public:
    static void SetCursorPosition(uint16_t x, uint16_t y)
    {
        std::cout << "\x1b[" << y << ";" << x << "H";
    }

    static void HorizontalLine(uint16_t x, uint16_t y, uint16_t length)
    {
        SetCursorPosition(x, y);
        for (auto i = 0; i < length; i++)
        {
            std::cout << "-";
        }
    }

    static void VerticalLine(uint16_t x, uint16_t y, uint16_t length)
    {
        for (auto i = 0; i < length; i++)
        {
            SetCursorPosition(x, y + i);
            std::cout << "|";
        }
    }

    static void HideCursor()
    {
        std::cout << "\x1b[?25l";
    }

    static void ShowCursor()
    {
        std::cout << "\x1b[?25h";
    }

    static void ClearScreen()
    {
        std::cout << "\x1b[2J";
    }
};
