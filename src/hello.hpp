#ifndef _SPARSE_MATRIX_
#define _SPARSE_MATRIX_

#include <iostream>
#include <cstddef> //for size_t
#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair

namespace spmv
{
  template <class fp_type>
  class SparseMatrix
  {
    //private:

  protected:
    size_t _nrows = 0;
    size_t _ncols = 0;
    size_t _nz = 0;

    std::map<std::pair<size_t, size_t>, fp_type> _buildCoeff;

  public:
    //This is the constructor
    SparseMatrix(const size_t nrows, const size_t ncols);
    ~SparseMatrix(); //This is the destructor
  };

}

#endif
