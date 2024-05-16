#pragma once
#include "TerminalHelper.h"

#pragma once

class CPrinter
{
public:
    virtual ~CPrinter() = default;
    virtual void Print(const ITerminalHelper &terminal) const = 0;
};
