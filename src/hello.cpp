#include "hello.hpp"


namespace spmv
{
template <class fp_type>
SparseMatrix<fp_type>::SparseMatrix(const size_t nrows, const size_t ncols) :
  _nrows(nrows), _ncols(ncols)
{
    std::cout << "Called SparseMatrix Constructor" << std::endl;
    //Intent of this routine is to create an instance of the class

    // If you're not familiar with C++ this is what you might do
    //this->_nrows = nrows;
    //this->_ncols = ncols;
}

template <class fp_type>
SparseMatrix<fp_type>::~SparseMatrix() {
    std::cout << "Called SparseMatrix Destructor" << std::endl;
    //Intent of this routine is to cleanup the object and
    //any memory associated with it.
}

template class SparseMatrix<float>;
template class SparseMatrix<double>;

}
