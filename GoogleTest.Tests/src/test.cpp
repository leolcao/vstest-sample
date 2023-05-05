#include "pch.h"

#include "cubic.h"

#include <iostream>

using namespace std;

TEST(TestCaseName, TestName)
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CubicTests, CheckValidInput)
{
  // Arrange
  double base = 2;
  double expect_val = 8;
  // Act
  auto result = cubic(base);
  cout << "result is: " << result << endl;
  // Assert
  EXPECT_EQ(result, expect_val);
}

TEST(CubicTests, CheckInvalidInput)
{
  // Arrange
  auto base = -2;
  auto expect_val = -1;
  // Act
  auto result = cubic(base);
  cout << "result is: " << result << endl;
  // Assert
  EXPECT_EQ(result, expect_val);
}
