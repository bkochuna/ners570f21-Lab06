#include "unit_test_framework.h"
#include <vector>

TEST(vector_compare) {
  std::vector<FP_TYPE> a = {1, 2, 3};
  std::vector<FP_TYPE> b = {1, 2, 3};
  ASSERT_SEQUENCE_EQUAL(a, b);
}

TEST(equal_int) {
  int m = 2;
  int n = 2;
  ASSERT_EQUAL(m, n);
}

TEST(not_equal_int) {
  int m = 2;
  int n = 2;
  ASSERT_EQUAL(m, n);
}
