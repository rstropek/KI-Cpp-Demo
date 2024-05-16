#pragma once

#include <cstdint>

enum Segment
{
    A = 0b0000001,
    B = 0b0000010,
    C = 0b0000100,
    D = 0b0001000,
    E = 0b0010000,
    F = 0b0100000,
    G = 0b1000000
};

class CSevenSegmentDisplay
{
private:
    // Single byte where each bit represents a segment (bit 1 = a, bit 2 = b, etc)
    uint8_t segments = 0;

public:
    CSevenSegmentDisplay() = default;
    CSevenSegmentDisplay(uint8_t initialValue)
    {
        SetSegments(initialValue);
    }

    void SetSegment(Segment segment, bool value);
    bool GetSegment(Segment segment) const;
    bool SetSegments(uint8_t value);
    uint8_t GetSegments() { return this->segments; }
};
