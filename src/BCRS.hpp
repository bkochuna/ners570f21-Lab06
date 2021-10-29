#ifndef _BCRS_MATRIX_
#define _BCRS_MATRIX_

#include "SparseMatrix.hpp"
#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>

namespace spmv {
template <class fp_type> class BCRS : public SparseMatrix<fp_type> {

private:
  std::vector<std::vector<std::vector<fp_type>>> _vals;
  std::vector<size_t> _ia;
  std::vector<size_t> _ja;
  size_t _nblk;

public:
  // This is the constructor
  BCRS(const size_t nrows, const size_t ncols)
      : SparseMatrix<fp_type>(nrows, ncols), _nblk(0){};

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
    Function : getBCRS
      Gets sparse matrix in BCRS format

    Parameters
    ----------
    vals : non-zero blocks in (block) row-wise fashion, size nblk by block size
    by block size ia   : pointer array that points to the beginning of each
    block row in val and ja, size _nrows + 1 ja   : column indices, size _nnz
    nblk : number of non-zero blocks
  */
  void getBCRS(std::vector<std::vector<std::vector<fp_type>>> &vals,
               std::vector<size_t> &ia, std::vector<size_t> &ja,
               size_t &nblk) const override;
};

} // namespace spmv

#endif
