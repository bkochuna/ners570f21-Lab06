Sparse Matrix-Vector Multiplication (SpMV)
==========================================

.. warning::

   This library is under active development. The code is likely to change frequently with possible breaking changes.

The Sparse Matrix-Vector Multiply (SpMV) library is a library to perform sparse matrix-vector Multiplication on single and double precision data types.
The library is under development with the following high-level requirements:

* The library shall be flexible in providing sparse matrices in several formats. 
* The library shall make use of Object-Oriented Design (and Programming) 
* The library shall make use of Design Patterns 
* The library shall be extensible 
* The library shall use a CMake based build system 
* The library shall use C++ and any of C or Fortran only. 

The detailed function requirements of the library are:

* The library shall provide an interface to perform sparse matrix vector multiplication. 
* The library shall support calculations in single precision arithmetic. 
* The library shall support calculations in double precision arithmetic. 
* The library shall provide an interface to return or define a matrix in COO Format 
* The library shall provide an interface to return or define a matrix in CRS Format 
* The library shall provide an interface to return or define a matrix in BCRS Format 
* The library shall provide an interface to return or define a matrix in JDS Format 
* The library shall provide an interface to return or define a matrix in ELLPACK Format

This documentation guide serves to centralize the documentation that is generated for the project, covering theory explanations, usage, examples, and information for how to develop the framework.
The guide contains the following sections:

.. toctree::
   :caption: Theory Manual
   :maxdepth: 2

   theoryManual/index

.. toctree::
   :caption: User Manual
   :maxdepth: 2

   userManual/index

.. toctree::
   :caption: Examples
   :maxdepth: 2

   examples/index

.. toctree::
   :caption: Developer Documentation
   :maxdepth: 2

   developerDocs/index
   developerDocs/cmake
   developerDocs/testing
