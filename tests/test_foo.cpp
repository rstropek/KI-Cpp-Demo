#include <gtest/gtest.h>
#include "../src/logic/foo.h"

TEST(FooTest, BasicAssertions) {
    // Expect foo() to print "Hello from foo!"
    testing::internal::CaptureStdout();
    foo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Hello from foo!\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
