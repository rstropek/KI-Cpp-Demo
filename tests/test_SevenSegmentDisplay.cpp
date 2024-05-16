#include "gtest/gtest.h"
#include "../src/logic/SevenSegmentDisplay.h"

TEST(SevenSegmentDisplayTest_SetSegment, SetSegment_ValidSegment_SegmentSet)
{
    CSevenSegmentDisplay display;
    display.SetSegment(Segment::A, true);
    EXPECT_TRUE(display.GetSegment(Segment::A));
}

TEST(SevenSegmentDisplayTest_SetSegment, SetSegment_ValidSegment_SegmentCleared)
{
    CSevenSegmentDisplay display;
    display.SetSegment(Segment::A, true);
    display.SetSegment(Segment::A, false);
    EXPECT_FALSE(display.GetSegment(Segment::A));
}

class SevenSegmentDisplayTest_SetSegment : public ::testing::TestWithParam<std::tuple<Segment, bool>>
{
protected:
    CSevenSegmentDisplay display;
};

TEST_P(SevenSegmentDisplayTest_SetSegment, SetSegment_InvalidSegment_ThrowsOutOfRange)
{
    Segment segment = std::get<0>(GetParam());
    bool value = std::get<1>(GetParam());
    EXPECT_THROW(display.SetSegment(segment, value), std::out_of_range);
}

INSTANTIATE_TEST_SUITE_P(InvalidSegmentValues, SevenSegmentDisplayTest_SetSegment,
    ::testing::Values(
        std::make_tuple(static_cast<Segment>(0), true),
        std::make_tuple(static_cast<Segment>(0b10000000), true),
        std::make_tuple(static_cast<Segment>(0b11111111), true)
    )
);

class SevenSegmentDisplayTest_GetSegment : public ::testing::TestWithParam<Segment>
{
protected:
    CSevenSegmentDisplay display;
};

TEST_P(SevenSegmentDisplayTest_GetSegment, GetSegment_InvalidSegment_ThrowsOutOfRange)
{
    Segment segment = GetParam();
    EXPECT_THROW(display.GetSegment(segment), std::out_of_range);
}

INSTANTIATE_TEST_SUITE_P(InvalidSegmentValues, SevenSegmentDisplayTest_GetSegment,
    ::testing::Values(
        static_cast<Segment>(0),
        static_cast<Segment>(0b10000000),
        static_cast<Segment>(0b11111111)
    )
);

TEST(SevenSegmentDisplayTest, SetSegments_ValidValue_SetsSegmentsCorrectly)
{
    CSevenSegmentDisplay display;
    display.SetSegments(8);
    EXPECT_EQ(display.GetSegment(Segment::A), true);
    EXPECT_EQ(display.GetSegment(Segment::B), true);
    EXPECT_EQ(display.GetSegment(Segment::C), true);
    EXPECT_EQ(display.GetSegment(Segment::D), true);
    EXPECT_EQ(display.GetSegment(Segment::E), true);
    EXPECT_EQ(display.GetSegment(Segment::F), true);
    EXPECT_EQ(display.GetSegment(Segment::G), true);
}

TEST(SevenSegmentDisplayTest, SetSegments_InvalidValue_ThrowsOutOfRange)
{
    CSevenSegmentDisplay display;
    EXPECT_THROW(display.SetSegments(10), std::out_of_range);
}