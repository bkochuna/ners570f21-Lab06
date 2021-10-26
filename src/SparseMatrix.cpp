#include "SparseMatrix.hpp"


namespace spmv
{

template <class fp_type>
size_t SparseMatrix<fp_type>::getnRows(){
	return _nrows;
} //getnRows

template <class fp_type>
size_t SparseMatrix<fp_type>::getnCols(){
	return _ncols;
} //getnCols

template <class fp_type>
size_t SparseMatrix<fp_type>::getnNZ(){
	return _nz;
} //getnNZ

template class SparseMatrix<float>;
template class SparseMatrix<double>;

}
