#include <iostream>
#include "logic/SevenSegmentDisplay.h"
#include "logic/SevenSegmentPrinter.h"
#include "logic/TerminalHelper.h"
#include "logic/NumberDisplay.h"
#include <thread>

int main() {
    CTerminalHelper terminal;
    terminal.ClearScreen();
    terminal.HideCursor();

    // CSevenSegmentDisplay display;
    // CSevenSegmentPrinter printer(0, 0, display);
    // display.SetSegments(8);
    // printer.Print();

    // display.SetSegments(2);
    // printer.Print();


    std::thread updateThread([&terminal]()
    {
        CNumberDisplay display(0);
        uint16_t currentValue = 0;
        while (true)
        {
            display.SetValue(++currentValue);
            //CTerminalHelper::ClearScreen();
            display.Print(terminal);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    updateThread.join();

    terminal.SetCursorPosition(13, 1);
    terminal.ShowCursor();
}

