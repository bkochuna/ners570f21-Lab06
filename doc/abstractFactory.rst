Abstract Factory Interface
==========================

The abstract factory for our Sparse Matrix is the following
![](images/factory.png) 

COO Matrix format
-----------------

The coordinate matrix format is fairly intuitive as it has 3 arrays: 1 float array of nonzero matrix values, and 2 integer arrays for the row and column indices

The implementation of the abstract factory code is 

.. code-block ::
    <insert code here>

To use it, the client  
TODO insert documentation

CRS Matrix format
-----------------

The Compressed Row Storage format for sparse matrices stores 1 float array and 2 integer arrays.
The float array is the matrix nonzero values.
The 2 integer arrays are the column indices of the nonzeros and the indices of the terms in the float array that start a row.

The implementation of the abstract factory code is 

.. code-block ::
    TODO insert some code from Chris

TODO insert documentation