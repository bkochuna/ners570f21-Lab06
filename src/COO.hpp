#ifndef _COO_MATRIX_
#define _COO_MATRIX_

#include "SparseMatrix.hpp"
#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>

namespace spmv {
template <class fp_type> class COO : public SparseMatrix<fp_type> {
private:
  std::vector<fp_type> _vals;
  std::vector<size_t> _idx_col;
  std::vector<size_t> _idx_row;

public:
  // This is the constructor
  COO(const size_t nrows, const size_t ncols)
      : SparseMatrix<fp_type>(nrows, ncols){};

  /*
        Function : setCoefficients
          Builds a sparse matrix

        Parameters
        ----------
        buildCoefficient
          a binary tree containing the [i, j] coordinates of non zero entries in
     the key and values in the values.

      */
  void setCoefficients(
      const std::map<std::pair<size_t, size_t>, fp_type> &buildCoeff) override;

  /*
      Function : getCOO
        Gets the Sparse matrix in COO format

      Parameters
      ----------
      vals : the values in the matrix, size nnz
      idx_col : column indices for the values, size nnz
      idx_row : row indices for the values, size nnz
      */
  void getCOO(std::vector<fp_type> &vals, std::vector<size_t> &idx_col,
              std::vector<size_t> &idx_row) const override;
};

} // namespace spmv

#endif
