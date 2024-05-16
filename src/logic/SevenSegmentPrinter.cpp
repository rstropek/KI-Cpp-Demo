#include "SevenSegmentPrinter.h"
#include <iostream>
#include "TerminalHelper.h"

void CSevenSegmentPrinter::Print() const
{
    if (display.GetSegment(Segment::A))
    {
        CTerminalHelper::HorizontalLine(2 + dx, 1 + dy, 8);
    }

    if (display.GetSegment(Segment::B))
    {
        CTerminalHelper::VerticalLine(10 + dx, 2 + dy, 3);
    }

    if (display.GetSegment(Segment::C))
    {
        CTerminalHelper::VerticalLine(10 + dx, 6 + dy, 3);
    }

    if (display.GetSegment(Segment::D))
    {
        CTerminalHelper::HorizontalLine(2 + dx, 9 + dy, 8);
    }

    if (display.GetSegment(Segment::E))
    {
        CTerminalHelper::VerticalLine(1 + dx, 6 + dy, 3);
    }

    if (display.GetSegment(Segment::F))
    {
        CTerminalHelper::VerticalLine(1 + dx, 2 + dy, 3);
    }

    if (display.GetSegment(Segment::G))
    {
        CTerminalHelper::HorizontalLine(2 + dx, 5 + dy, 8);
    }
}

void CSevenSegmentPrinter::Clear() const
{
    for (uint8_t row = 1; row <= 9; row++)
    {
        if (row == 1 || row == 5 || row == 9)
        {
            CTerminalHelper::SetCursorPosition(dx + 2, dy + row);
            std::cout << "          ";
        }
        else
        {
            CTerminalHelper::SetCursorPosition(1 + dx, dy + row);
            std::cout << ' ';
            CTerminalHelper::SetCursorPosition(dx + 10, dy + row);
            std::cout << ' ';
        }
    }
}
