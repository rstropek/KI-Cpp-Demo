#include "NumberDisplay.h"
#include <stdexcept>

CNumberDisplay::CNumberDisplay(uint16_t initialValue) : value(initialValue), digits(), printers()
{
    if (initialValue > 9999)
    {
        throw std::out_of_range("Initial value out of range");
    }

    digits.reserve(4);
    printers.reserve(4);
    digits.push_back(CSevenSegmentDisplay(value / 1000));
    digits.push_back(CSevenSegmentDisplay((value / 100) % 10));
    digits.push_back(CSevenSegmentDisplay((value / 10) % 10));
    digits.push_back(CSevenSegmentDisplay(value % 10));

    for (std::size_t i = 0; i < digits.size(); ++i)
    {
        printers.push_back(CSevenSegmentPrinter(i * 13, 0, digits[i]));
    }
}

void CNumberDisplay::SetValue(uint16_t newValue)
{
    if (value == newValue)
    {
        return;
    }

    if (newValue > 9999)
    {
        throw std::out_of_range("New value out of range");
    }

    digits[0].SetSegments(newValue / 1000);
    digits[1].SetSegments((newValue / 100) % 10);
    digits[2].SetSegments((newValue / 10) % 10);
    digits[3].SetSegments(newValue % 10);
}

void CNumberDisplay::Print() const
{
    for (uint8_t ix = 0; ix < 4; ++ix)
    {
        printers[ix].Clear();
        printers[ix].Print();
    }
}
