#pragma once
#include "SevenSegmentDisplay.h"
#include "SevenSegmentPrinter.h"
#include "Printer.h"
#include <vector>
#include <stdexcept>

class CNumberDisplay : public CPrinter
{
private:
    uint16_t value;
    std::vector<CSevenSegmentDisplay> digits;
    std::vector<CSevenSegmentPrinter> printers;

public:
    CNumberDisplay() : CNumberDisplay(0) {}
    CNumberDisplay(uint16_t initialValue);

    void SetValue(uint16_t newValue);
    void Print() const override;
};
