#include <stdexcept>
#include "SevenSegmentDisplay.h"

void CSevenSegmentDisplay::SetSegment(Segment segment, bool value)
{
    // Check that segment is a valid value
    switch (segment)
    {
    case Segment::A:
    case Segment::B:
    case Segment::C:
    case Segment::D:
    case Segment::E:
    case Segment::F:
    case Segment::G:
        // Segment is valid, proceed with bitwise operations
        if (value)
        {
            segments |= segment;
        }
        else
        {
            segments &= ~segment;
        }
        break;
    default:
        throw std::out_of_range("Invalid segment value");
    }
}

bool CSevenSegmentDisplay::GetSegment(Segment segment) const
{
    // Check that segment is a valid value
    switch (segment)
    {
    case Segment::A:
    case Segment::B:
    case Segment::C:
    case Segment::D:
    case Segment::E:
    case Segment::F:
    case Segment::G:
        // Segment is valid, proceed with bitwise operations
        return (segments & segment) != 0;
    default:
        throw std::out_of_range("Invalid segment value");
    }
}

bool CSevenSegmentDisplay::SetSegments(uint8_t value)
{
    uint8_t newSegments;
    switch (value)
    {
    case 0:
        newSegments = Segment::A | Segment::B | Segment::C | Segment::D | Segment::E | Segment::F;
        break;
    case 1:
        newSegments = Segment::B | Segment::C;
        break;
    case 2:
        newSegments = Segment::A | Segment::B | Segment::D | Segment::E | Segment::G;
        break;
    case 3:
        newSegments = Segment::A | Segment::B | Segment::C | Segment::D | Segment::G;
        break;
    case 4:
        newSegments = Segment::B | Segment::C | Segment::F | Segment::G;
        break;
    case 5:
        newSegments = Segment::A | Segment::C | Segment::D | Segment::F | Segment::G;
        break;
    case 6:
        newSegments = Segment::A | Segment::C | Segment::D | Segment::E | Segment::F | Segment::G;
        break;
    case 7:
        newSegments = Segment::A | Segment::B | Segment::C;
        break;
    case 8:
        newSegments = Segment::A | Segment::B | Segment::C | Segment::D | Segment::E | Segment::F | Segment::G;
        break;
    case 9:
        newSegments = Segment::A | Segment::B | Segment::C | Segment::D | Segment::F | Segment::G;
        break;
    default:
        throw std::out_of_range("Invalid segment value");
    }

    bool result = segments != newSegments;
    segments = newSegments;
    return result;
}

