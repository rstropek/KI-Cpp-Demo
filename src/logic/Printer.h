#pragma once

#pragma once

class CPrinter
{
public:
    virtual ~CPrinter() = default;
    virtual void Print() const = 0;
};
