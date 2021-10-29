#ifndef _SPARSE_MATRIX_
#define _SPARSE_MATRIX_

#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>

namespace spmv {
template <class fp_type> class SparseMatrix {

protected:
  size_t _nrows = 0;
  size_t _ncols = 0;
  size_t _nz = 0;

  std::map<std::pair<size_t, size_t>, fp_type> _buildCoeff;

public:
  // This is the constructor
  SparseMatrix(const size_t nrows, const size_t ncols)
      : _nrows(nrows), _ncols(ncols), _nz(0){};

  // virtual dtor
  virtual ~SparseMatrix(){};

  /*
        Function : setCoefficients
          Builds a sparse matrix

        Parameters
        ----------
        buildCoefficient
          a binary tree containing the [i, j] coordinates of non zero entries in
     the key and values in the values.

      */
  virtual void setCoefficients(
      const std::map<std::pair<size_t, size_t>, fp_type> &buildCoeff) = 0;

  /*
        Function : matVec
          Preforms matrix vector multiplication

        Parameters
        ----------
        x : vector of length equal to the number of columns in the matrix to
     multiply b : vector of length equal to the number of columns in the matrix
     that is the result of the multiplication

      */
  virtual void matVec(const std::vector<fp_type> &x,
                      std::vector<fp_type> &b) const;

  /*
        Function : getnRows
          Returns the number of rows in the matrix

        Returns
        ----------
          _nrows
      */
  size_t getnRows();

  /*
        Function : getnCols
          Returns the number of cols in the matrix

        Returns
        ----------
          _ncols
      */
  size_t getnCols();

  /*
        Function : getnNZ
          Returns the number of non-zeros in the matrix

        Returns
        ----------
          _nz
      */
  size_t getnNZ();

  /*
      Function : getCOO
        Gets the Sparse matrix in COO format

      Parameters
      ----------
      vals : the values in the matrix, size nnz
      idx_col : column indices for the values, size nnz
      idx_row : row indices for the values, size nnz
      */
  virtual void getCOO(std::vector<fp_type> &vals, std::vector<size_t> &idx_col,
                      std::vector<size_t> &idx_row) const;

  /*
        Function : getELLPACK
          Gets the sparse matrix in ELLPACK format

        Parameters
        ----------
        vals      : the values in the matrix, size nnz
        ja        : a 2d vector of size _nrows by maxnz_row that contains column
     indices
      */
  virtual void getELLPACK(std::vector<fp_type> &vals,
                          std::vector<std::vector<size_t>> &ja,
                          size_t &maxnz_row) const;

  /*
        Function : getCRS
          Gets sparse matrix in CRS format

        Parameters
        ----------
        vals : values in the matrix, size _nnz
        ja   : column indices, size _nnz
        ia   : row indices, size _nrows + 1
      */
  virtual void getCRS(std::vector<fp_type> &vals, std::vector<size_t> &ia,
                      std::vector<size_t> &ja) const;

  /*
        Function : getBCRS
          Gets sparse matrix in BCRS format

        Parameters
        ----------
        vals : non-zero blocks in (block) row-wise fashion, size nblk by block
     size by block size ia   : pointer vector that points to the beginning of
     each block row in val and ja, size _nrows + 1 ja   : column indices, size
     _nnz nblk : number of non-zero blocks
      */
  virtual void getBCRS(std::vector<std::vector<std::vector<fp_type>>> &vals,
                       std::vector<size_t> &ia, std::vector<size_t> &ja,
                       size_t &nBlks) const;

  /*
        Function : getJDS
          Gets sparse matrix in JDS format

          Parameters
          ----------
        perm    : permutation vector that reorders the rows, size _nrows
        jdiag   : vector containing jagged diagonals in succession, size
     non_zero in first row col_ind : vector containing coresponding column
     indices, size non_zero in first row jd_ptr  : pointer vector indexing to
     the beginning of each jagged diagonal, size nn_zero in first row
      */
  virtual void getJDS(std::vector<size_t> &perm, std::vector<fp_type> &jdiag,
                      std::vector<size_t> &col_ind,
                      std::vector<size_t> &jd_ptr) const;
};
} // namespace spmv

#endif