# Running tests

To run all tests, enter the `test` directory and run the `run_tests.sh` shell script.

# Adding tests

To add tests, create a new file whose filename begins with `test` and ends with `.cpp` (the test will not be identified by `run_tests.sh` if this is not the case). Any number of tests can be added to a single file. Add tests in the following format:

```
#include "unit_testing_framework.h"

TEST(<first test name here>) {
    // Contents of test go here
    ASSERT_TRUE(<test correctness here>)
}

TEST(<second test name here>) {
    // Contents of test go here
    ASSERT_TRUE(<test correctness here>)  // could use any (or multiple) of the available assert statements
}

...
```

**Use `FP_TYPE` in the place of `float` or `double` when instantiating variables (or sparse matrices) that are meant to be tested with both single and double precision.** For example, one test case that uses this may look like

```
TEST(fp_equal) {
    FP_TYPE a = 1.;
    FP_TYPE b = 1.00000001;
    ASSERT_ALMOST_EQUAL(a, b, 0.0001);
}
```

## Assert statements

A number of assert statements are available to use in the tests:

`ASSERT_EQUAL(first, second)`
* If `first == second` evaluates to false, the test will fail.
* `first` and `second` may be any type with the `==` operator defined.

`ASSERT_NOT_EQUAL(first, second)`
* If `first != second` evaluates to false, the test will fail.
* `first` and `second` may be any type with the `==` operator defined.

`ASSERT_TRUE(bool value)`
* If `value` is false, the test will fail.

`ASSERT_FALSE(bool value)`
* If `value` is true, the test will fail.

`ASSERT_ALMOST_EQUAL(double first, double second, double precision)`
* If `first` and `second` are not equal within `precision`, the test will fail.

`ASSERT_SEQUENCE_EQUAL(first, second)`
* If `first` and `second` do not have equal elements, the test will fail.
* `first` and `second` may be any sequence types (e.g. arrays, vectors, lists), as long as their elements are comparable with `==`.

## More information

This test framework is based on the EECS 280 open source unit testing framework. Their documentation can be found [here](https://eecs280staff.github.io/unit_test_framework/) and the source code can be found [here](https://github.com/eecs280staff/unit_test_framework).