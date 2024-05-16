#pragma once

#include <cstdint>
#include <iostream>

class ITerminalHelper {
public:
    virtual ~ITerminalHelper() = default;
    virtual void HorizontalLine(uint16_t x, uint16_t y, uint16_t length) const = 0;
    virtual void VerticalLine(uint16_t x, uint16_t y, uint16_t length) const = 0;
    virtual void SetCursorPosition(uint16_t x, uint16_t y) const = 0;
    virtual void HideCursor() const = 0;
    virtual void ShowCursor() const = 0;
    virtual void ClearScreen() const = 0;
};

class CTerminalHelper : public ITerminalHelper
{
public:
    void SetCursorPosition(uint16_t x, uint16_t y) const override
    {
        std::cout << "\x1b[" << y << ";" << x << "H";
    }

    void HorizontalLine(uint16_t x, uint16_t y, uint16_t length) const override
    {
        SetCursorPosition(x, y);
        for (auto i = 0; i < length; i++)
        {
            std::cout << "-";
        }
    }

    void VerticalLine(uint16_t x, uint16_t y, uint16_t length) const override
    {
        for (auto i = 0; i < length; i++)
        {
            SetCursorPosition(x, y + i);
            std::cout << "|";
        }
    }

    void HideCursor() const override
    {
        std::cout << "\x1b[?25l";
    }

    void ShowCursor() const override
    {
        std::cout << "\x1b[?25h";
    }

    void ClearScreen() const override
    {
        std::cout << "\x1b[2J";
    }
};
