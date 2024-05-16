#include <iostream>
#include "logic/SevenSegmentDisplay.h"
#include "logic/SevenSegmentPrinter.h"
#include "logic/TerminalHelper.h"
#include "logic/NumberDisplay.h"
#include <thread>

int main() {
    CTerminalHelper::ClearScreen();
    CTerminalHelper::HideCursor();

    // CSevenSegmentDisplay display;
    // CSevenSegmentPrinter printer(0, 0, display);
    // display.SetSegments(8);
    // printer.Print();

    // display.SetSegments(2);
    // printer.Print();

    CNumberDisplay display(0);

    std::thread updateThread([&display]()
    {
        uint16_t currentValue = 0;
        while (true)
        {
            display.SetValue(++currentValue);
            //CTerminalHelper::ClearScreen();
            display.Print();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    updateThread.join();

    CTerminalHelper::SetCursorPosition(13, 1);
    CTerminalHelper::ShowCursor();
}

