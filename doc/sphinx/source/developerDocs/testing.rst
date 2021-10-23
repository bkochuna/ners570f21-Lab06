.. _testing:

Testing Framework
=================

General testing for every format
--------------------------------

Sparse matrix vector multiplication interface
*********************************************

Tests for these will include

* identity matrix with vector and make sure it returns the vector
* diagonal matrix with increasing numbers along diagonal
* matrix of zeros and make sure returned vector is zero
* tridiagonal banded matrix
* a random matrix and random vector checked against a simple dense matrix vector multiplication (setting the random seed at the beginning of the test to ensure reproducibility)

Single/double precision
***********************

* Define a testing class that is templated to define whether or not to use single or double precision data types
* This approach will allow us to run all the tests with both double and single precision types without duplicating any of the code

Unit/integration tests for each matrix format
*********************************************

* Generate some sparse matrix and store it in each of the specified matrix formats—compare the matrices to make sure each format looks identical from outside the class
* Test accessing and setting of nonzero entries
* Test accessing and setting of zero entries
* Test setting nonzero entries to zero and check that the values are removed from the stored data
* Test setting additional nonzero entries

Format-specific tests
---------------------

COO Format
*************

* Generate a dense matrix with known column and row index arrays for each element
* Create the matrix using the COO function
* Test that the column/row/element arrays are all of length equal to the number of elements in the matrix.
* Test that the elements of the column and row index arrays generate the same as the predetermined arrays.

CRS Format
**********
* Generate a dense matrix with known column and row index arrays for each element
* Create the matrix using the CRS function
* Test that the column/row/element array are all of length equal to the number of elements in the matrix.
* Test that the elements in the index arrays are the same as the known arrays.

BCRS Format
***********

* Generate a dense matrix with known column/row indices for each element
* Create the matrix using the BCRS function
* Test that the blocks match the associated blocks 
* Depending on our implementation, we also test against different block sizes, make sure that if the block size is 1 we reach csr in the limit

JDS Format
**********

* Generate a dense matrix with known diagonal value and column index arrays
* Create the matrix using the JDS function
* Check the size of the diagonal value and column index arrays are the same and match the size of the predetermined arrays.
* Test that the elements in the diagonal value and column index array match with the predetermined arrays.

ELLPACK Format
**************

* Generate a dense matrix with known column and row index arrays for each element
* Create the matrix using ELLPACK function
* Check that the size of the column index matrix to make sure that it is a square matrix with number of rows/columns equal to the size of the dense matrix
* Check that the values in the matrix of value math the dense matrix exactly.
