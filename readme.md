# Notes

## How to build Google Tests

```bash
cmake -A=Win32 -Dgtest_force_shared_crt=ON ..
cmake --build . --config Debug
```
