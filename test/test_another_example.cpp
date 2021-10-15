#include "unit_test_framework.h"

TEST(test_true) {
  ASSERT_TRUE(true);
}

TEST(test_false) {
  ASSERT_FALSE(false);
}

TEST(test_almost_equal) {
  FP_TYPE a = 1.;
  FP_TYPE b = 1.0000001;
  ASSERT_ALMOST_EQUAL(a, b, 0.0001);
  ASSERT_TRUE(b - a > 0);
}
