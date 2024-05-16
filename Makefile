# Makefile for cl.exe with a single command

# Compiler and flags
CXX = "cl"
CXXFLAGS = /EHsc /Zi /DEBUG /I "..\googletest\googletest\include" /I "..\googletest\googletest" /I "..\googletest\googlemock\include"  /I "..\googletest\googlemock" /MDd
LDFLAGS = /link /LIBPATH:"..\googletest\build\lib\Debug" gtest.lib gmock.lib gtest_main.lib
OBJ_DIR = obj
TARGET_DIR = target
EXEC = $(TARGET_DIR)\helloworld.exe
TEST_EXEC = $(TARGET_DIR)\test_helloworld.exe

# Source files
SRC = src\*.cpp src\logic\*.cpp
TEST_SRC = tests\*.cpp src\logic\*.cpp

# Default target
all: rebuild

rebuild: clean $(EXEC) $(TEST_EXEC)

# Build target
$(EXEC):
    if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
    if not exist $(TARGET_DIR) mkdir $(TARGET_DIR)
    $(CXX) $(CXXFLAGS) /Fo"$(OBJ_DIR)\\" /Fe"$(EXEC)" $(SRC)

# Build test executable
$(TEST_EXEC):
    if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
    if not exist $(TARGET_DIR) mkdir $(TARGET_DIR)
    $(CXX) $(CXXFLAGS) /Fo"$(OBJ_DIR)\\" /Fe"$(TEST_EXEC)" $(TEST_SRC) $(LDFLAGS)

# Clean the build directory
clean:
    if exist $(OBJ_DIR) rd /s /q $(OBJ_DIR)
    if exist $(TARGET_DIR) rd /s /q $(TARGET_DIR)

.PHONY: all clean
