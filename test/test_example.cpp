#include "unit_test_framework.h"

TEST(test_pass) {
  ASSERT_TRUE(true);
}

TEST(test_fail) {
  ASSERT_TRUE(false);
}

TEST(test_almost_equal) {
  FP_TYPE x = 1.;
  FP_TYPE y = 1.0000001;
  ASSERT_ALMOST_EQUAL(x, y, 0.0001);
}

TEST_MAIN() // No semicolon!