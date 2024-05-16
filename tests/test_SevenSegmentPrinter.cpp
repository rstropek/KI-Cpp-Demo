#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/logic/TerminalHelper.h"
#include "../src/logic/SevenSegmentPrinter.h"
#include "../src/logic/SevenSegmentDisplay.h"

class MockTerminalHelper : public ITerminalHelper {
public:
    MOCK_CONST_METHOD3(HorizontalLine, void(uint16_t x, uint16_t y, uint16_t length));
    MOCK_CONST_METHOD3(VerticalLine, void(uint16_t x, uint16_t y, uint16_t length));
    MOCK_CONST_METHOD2(SetCursorPosition, void(uint16_t x, uint16_t y));
    MOCK_CONST_METHOD0(HideCursor, void());
    MOCK_CONST_METHOD0(ShowCursor, void());
    MOCK_CONST_METHOD0(ClearScreen, void());

};

class CSevenSegmentPrinterTest : public ::testing::Test {
protected:
    MockTerminalHelper mockTerminalHelper;
    CSevenSegmentDisplay display;
    CSevenSegmentPrinter printer{0, 0, display};
};

TEST_F(CSevenSegmentPrinterTest, Print_CallsHorizontalLine_WhenSegmentAIsSet) {
    EXPECT_CALL(mockTerminalHelper, HorizontalLine(2, 1, 8)).Times(1);

    display.SetSegment(Segment::A, true);
    
    printer.Print(mockTerminalHelper);

    // Verification is done automatically at the end of the scope
}
