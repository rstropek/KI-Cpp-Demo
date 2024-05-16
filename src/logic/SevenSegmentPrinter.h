#pragma once

#include <cstdint>
#include "SevenSegmentDisplay.h"
#include "Printer.h"

class CSevenSegmentPrinter : public CPrinter
{
private:
    const CSevenSegmentDisplay &display;
    uint16_t dx;
    uint16_t dy;

public:
    CSevenSegmentPrinter(uint16_t dx, uint16_t dy, const CSevenSegmentDisplay &display)
        : display(display), dx(dx), dy(dy) { }

    void Print() const override;
    void Clear() const;
};
