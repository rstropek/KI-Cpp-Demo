```bash
cmake -A=Win32 -Dgtest_force_shared_crt=ON ..
cmake --build . --config Debug
```

* Turn literals into binary values
* Write C++ Google Tests for the method @fn:SetSegment()
* Write a data-driven Google C++ test for @fn:SetSegment() (SevenSegmentDisplay.cpp:4-29:2) that verifies that an exception is thrown if segment is 0, if segment has multiple bits set, if segment is 0b10000000

