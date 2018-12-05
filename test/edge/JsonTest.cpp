//
// Created by larryhsiao on 12/5/18.
//
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

#define TEST_SUIT Json

TEST(TEST_SUIT, serializeTest) {
    auto j2 = R"(
  {
    "Field1": true,
    "pi": 3.141,
    "Field3": "Value2"
  }
    )"_json;

    ASSERT_TRUE(j2["Field1"]);
    ASSERT_EQ(3.141, j2["pi"]);
    ASSERT_EQ("Value2", j2["Field3"]);
}