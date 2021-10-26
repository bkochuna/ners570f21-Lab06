#include <vector>
#include "SparseMatrix.hpp"

namespace spmv
{
  template <class fp_type>
  SparseMatrix<fp_type>::SparseMatrix(const size_t nrows, const size_t ncols) : _nrows(nrows), _ncols(ncols)
  {
    std::cout << "Called SparseMatrix Constructor" << std::endl;
    //Intent of this routine is to create an instance of the class

    // If you're not familiar with C++ this is what you might do
    //this->_nrows = nrows;
    //this->_ncols = ncols;
  }

  template <class fp_type>
  SparseMatrix<fp_type>::~SparseMatrix()
  {
    std::cout << "Called SparseMatrix Destructor" << std::endl;
    //Intent of this routine is to cleanup the object and
    //any memory associated with it.
  }

  template <class fp_type>
  size_t SparseMatrix<fp_type>::getnRows()
  {
    return _nrows;
  } //getnRows

  template <class fp_type>
  size_t SparseMatrix<fp_type>::getnCols()
  {
    return _ncols;
  } //getnCols

  template <class fp_type>
  size_t SparseMatrix<fp_type>::getnNZ()
  {
    return _nz;
  } //getnNZ

  template <class fp_type>
  void SparseMatrix<fp_type>::matVec(const std::vector<fp_type> &x, std::vector<fp_type> &b) const
  {
  }

  template <class fp_type>
  void SparseMatrix<fp_type>::getCOO(std::vector<fp_type> &vals, std::vector<size_t> &idx_col, std::vector<size_t> &idx_row) const
  {
  }

  template <class fp_type>
  void SparseMatrix<fp_type>::getELLPACK(std::vector<fp_type> &vals, std::vector<std::vector<size_t> > &ja, size_t &maxnz_row) const
  {
  }

  template <class fp_type>
  void SparseMatrix<fp_type>::getCRS(std::vector<fp_type> &vals, std::vector<size_t> &ia, std::vector<size_t> &ja) const
  {
  }

  template <class fp_type>
  void SparseMatrix<fp_type>::getBCRS(std::vector<std::vector<std::vector<fp_type> > > &vals, std::vector<size_t> &ia, std::vector<size_t> &ja, size_t &nBlks) const
  {
  }

  template <class fp_type>
  void SparseMatrix<fp_type>::getJDS(std::vector<size_t> &perm, std::vector<fp_type> &jdiag, std::vector<size_t> &col_ind, std::vector<size_t> &jd_ptr) const
  {
  }

  template class SparseMatrix<float>;
  template class SparseMatrix<double>;

}
