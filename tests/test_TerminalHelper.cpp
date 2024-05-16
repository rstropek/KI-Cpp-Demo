#include "gtest/gtest.h"
#include "../src/logic/TerminalHelper.h"

TEST(TerminalHelperTest, SetCursorPosition) {
    testing::internal::CaptureStdout();
    CTerminalHelper terminal;
    terminal.SetCursorPosition(10, 5);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\x1b[5;10H");
}

TEST(TerminalHelperTest, HorizontalLine) {
    testing::internal::CaptureStdout();
    CTerminalHelper terminal;
    terminal.HorizontalLine(0, 0, 10);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\x1b[0;0H" + std::string(10, '-'));
}

TEST(TerminalHelperTest, VerticalLine) {
    testing::internal::CaptureStdout();
    CTerminalHelper terminal;
    terminal.VerticalLine(0, 0, 10);
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "\x1b[0;0H|";
    for (int i = 1; i < 10; i++) {
        expected += "\x1b[" + std::to_string(i) + ";0H|";
    }
    EXPECT_EQ(output, expected);
}

TEST(TerminalHelperTest, HideCursor) {
    testing::internal::CaptureStdout();
    CTerminalHelper terminal;
    terminal.HideCursor();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\x1b[?25l");
}

TEST(TerminalHelperTest, ShowCursor) {
    testing::internal::CaptureStdout();
    CTerminalHelper terminal;
    terminal.ShowCursor();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\x1b[?25h");
}

TEST(TerminalHelperTest, ClearScreen) {
    testing::internal::CaptureStdout();
    CTerminalHelper terminal;
    terminal.ClearScreen();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\x1b[2J");
}
