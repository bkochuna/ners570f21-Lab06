.. _testing:

Testing
=======

Testing Framework
-----------------

Running tests
*************

To run all tests, configure with tests (enabled by default right now) and then:

.. prompt:: bash

    make
    make test

Adding tests
************

To add a new testing file create a new C++ file (with a ``.cpp`` extension) and append ``add_unit_test(<filename>)`` to ``test/CMakeLists.txt`` where ``<filename>`` is the test filename without the ``.cpp`` extension.
Any number of tests can be added to a single file.
Each test file should have one call to ``TEST_MAIN()`` at the bottom.
Add tests in the following format:

.. code-block:: cpp

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

    TEST_MAIN()

.. note::

    Use ``FP_TYPE`` in the place of ``float`` or ``double`` when instantiating variables (or sparse matrices) that are meant to be tested with both single and double precision.
    For example, one test case that uses this may look like

    .. code-block:: cpp

        TEST(fp_equal) {
            FP_TYPE a = 1.;
            FP_TYPE b = 1.00000001;
            ASSERT_ALMOST_EQUAL(a, b, 0.0001);
        }


After you have a source file with the test you want, you must add that source file to the `CMakeLits.txt` file. 
This can be done in one line using the `add_unit_test` macro:

.. code-block:: cpp

    ...
    add_unit_test(example_test)
    ...


The name passed into the macro is the file name without the ``.cpp`` extension.
The macro will create targets for both single and double precision and add the appropriate tests.

Assert statements
*****************

A number of assert statements are available to use in the tests:

``ASSERT_EQUAL(first, second)``

* If ``first == second`` evaluates to false, the test will fail.
* ``first`` and ``second`` may be any type with the ``==`` operator defined.

``ASSERT_NOT_EQUAL(first, second)``

* If ``first != second`` evaluates to false, the test will fail.
* ``first`` and ``second`` may be any type with the ``==`` operator defined.

``ASSERT_TRUE(bool value)``

* If ``value`` is false, the test will fail.

``ASSERT_FALSE(bool value)``

* If ``value`` is true, the test will fail.

``ASSERT_ALMOST_EQUAL(double first, double second, double precision)``

* If ``first`` and ``second`` are not equal within ``precision``, the test will fail.

``ASSERT_SEQUENCE_EQUAL(first, second)``

* If ``first`` and ``second`` do not have equal elements, the test will fail.
* ``first`` and ``second`` may be any sequence types (e.g. arrays, vectors, lists), as long as their elements are comparable with ``==``.

More information
****************

This test framework is based on the EECS 280 open source unit testing framework.
The documentation can be found `on class documentation page <https://eecs280staff.github.io/unit_test_framework/>`_ and the source code can be found `on the class GitHub <https://github.com/eecs280staff/unit_test_framework>`_.

Testing Methodology
-------------------

Sparse matrix vector multiplication interface
*********************************************

Tests for these will include

* identity matrix with vector and make sure it returns the vector
* diagonal matrix with increasing numbers along diagonal
* matrix of zeros and make sure returned vector is zero
* tridiagonal banded matrix
* a random matrix and random vector checked against a simple dense matrix vector multiplication (setting the random seed at the beginning of the test to ensure reproducibility)

**Single/double precision**

* Define a testing class that is templated to define whether or not to use single or double precision data types
* This approach will allow us to run all the tests with both double and single precision types without duplicating any of the code

**Unit/integration tests for each matrix format**

* Generate some sparse matrix and store it in each of the specified matrix formats—compare the matrices to make sure each format looks identical from outside the class
* Test accessing and setting of nonzero entries
* Test accessing and setting of zero entries
* Test setting nonzero entries to zero and check that the values are removed from the stored data
* Test setting additional nonzero entries

Format-specific tests
*********************

**COO Format**

* Generate a dense matrix with known column and row index arrays for each element
* Create the matrix using the COO function
* Test that the column/row/element arrays are all of length equal to the number of elements in the matrix.
* Test that the elements of the column and row index arrays generate the same as the predetermined arrays.

**CRS Format**

* Generate a dense matrix with known column and row index arrays for each element
* Create the matrix using the CRS function
* Test that the column/row/element array are all of length equal to the number of elements in the matrix.
* Test that the elements in the index arrays are the same as the known arrays.

**BCRS Format**

* Generate a dense matrix with known column/row indices for each element
* Create the matrix using the BCRS function
* Test that the blocks match the associated blocks 
* Depending on our implementation, we also test against different block sizes, make sure that if the block size is 1 we reach csr in the limit

**JDS Format**

* Generate a dense matrix with known diagonal value and column index arrays
* Create the matrix using the JDS function
* Check the size of the diagonal value and column index arrays are the same and match the size of the predetermined arrays.
* Test that the elements in the diagonal value and column index array match with the predetermined arrays.

**ELLPACK Format**

* Generate a dense matrix with known column and row index arrays for each element
* Create the matrix using ELLPACK function
* Check that the size of the column index matrix to make sure that it is a square matrix with number of rows/columns equal to the size of the dense matrix
* Check that the values in the matrix of value math the dense matrix exactly.
