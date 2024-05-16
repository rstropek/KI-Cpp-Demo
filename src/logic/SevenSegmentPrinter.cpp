#include "SevenSegmentPrinter.h"
#include <iostream>
#include "TerminalHelper.h"

void CSevenSegmentPrinter::Print(const ITerminalHelper &terminal) const
{
    if (display.GetSegment(Segment::A))
    {
        terminal.HorizontalLine(2 + dx, 1 + dy, 8);
    }

    if (display.GetSegment(Segment::B))
    {
        terminal.VerticalLine(10 + dx, 2 + dy, 3);
    }

    if (display.GetSegment(Segment::C))
    {
        terminal.VerticalLine(10 + dx, 6 + dy, 3);
    }

    if (display.GetSegment(Segment::D))
    {
        terminal.HorizontalLine(2 + dx, 9 + dy, 8);
    }

    if (display.GetSegment(Segment::E))
    {
        terminal.VerticalLine(1 + dx, 6 + dy, 3);
    }

    if (display.GetSegment(Segment::F))
    {
        terminal.VerticalLine(1 + dx, 2 + dy, 3);
    }

    if (display.GetSegment(Segment::G))
    {
        terminal.HorizontalLine(2 + dx, 5 + dy, 8);
    }
}

void CSevenSegmentPrinter::Clear(const ITerminalHelper &terminal) const
{
    for (uint8_t row = 1; row <= 9; row++)
    {
        if (row == 1 || row == 5 || row == 9)
        {
            terminal.SetCursorPosition(dx + 2, dy + row);
            std::cout << "          ";
        }
        else
        {
            terminal.SetCursorPosition(1 + dx, dy + row);
            std::cout << ' ';
            terminal.SetCursorPosition(dx + 10, dy + row);
            std::cout << ' ';
        }
    }
}
