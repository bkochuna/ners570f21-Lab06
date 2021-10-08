# General testing for every format

## Sparse matrix vector multiplication interface
Tests for these will include
* identity matrix with vector and make sure it returns the vector
* diagonal matrix with increasing numbers along diagonal
* matrix of zeros and make sure returned vector is zero
* tridiagonal banded matrix
* a random matrix and random vector checked against a simple dense matrix vector multiplication (setting the random seed at the beginning of the test to ensure reproducibility)

## Single/double precision
* For testing single and double precision use compiler directives to specify single or double precision at compile time to generate single and double precision tests. This way each format is tested for the same things, but  
* Check input and output types of each are as expected (this may or may not compile depending on if compilation quits when types are cast)

## Unit/integration tests for each matrix format
* Generate some sparse matrix and directly store it. Store the matrix in each of the listed formats and compare.
* Test accessing and setting of nonzero entries
* Test accessing and setting of zero entries
* Test setting nonzero entries to zero and check that the values are removed from the stored data


# Format-specific tests
## COO Format
* Generate a dense matrix with known column and row index arrays for each element
* Create the matrix using the COO function
* Test that the elements of the column and row index arrays generate the same as the predetermined arrays.
## CRS Format
* Generate a dense matrix with known column and row index arrays for each element
* Create the matrix using the CRS function
* Test that the elements in the index arrays are the same as the known arrays.
## BCRS Format

## JDS Format

## ELLPACK Format