#include <map>
#include <utility>
#include <vector>
#include "CRS.hpp"

namespace spmv
{
template <class fp_type>
void CRS<fp_type>::setCoefficients(const std::map< std::pair<size_t,size_t> , fp_type > &buildCoeff) {

}

template <class fp_type>
void CRS<fp_type>::getCRS(std::vector<fp_type> &vals, std::vector<size_t> &ia, std::vector<size_t> &ja)  const {
   
    int nnz, i, j, nz, ncols, nrows;
    ncols = sizeof(ia) - 1;
    nrows = sizeof(ia) - 1;
    fp_type ** A = new fp_type*[ncols];
    for (int i = 0; i < ncols; i++) {
        A[i] = new fp_type[nrows];
    }   

    for (i = 1; i<=ncols; i=i+1) {//row
        for (j = 1; j<=ncols; j=j+1) { // coloumn
            if ((ja[nnz] == j) && (nnz <= ia[i])) {
                A[i][j] = vals[nnz];
                nnz = nnz+1;
            }
            else {
                A[i][j] = 0;
            }
        }
    }
    nz = nnz;

}

template <class fp_type>
std::vector<fp_type> CRS<fp_type>::getValues() {
    return _vals;
}

template <class fp_type>
std::vector<size_t> CRS<fp_type>::getRowsIndices() {
    return _ia;
}

template <class fp_type>
std::vector<size_t> CRS<fp_type>::getColsIndices() {
    return _ja;
}

template <class fp_type>
int CRS<fp_type>::getNRows() {
    return nrows;
}

template <class fp_type>
int CRS<fp_type>::getNCols() { 
    return ncols;
}


template class CRS<float>;
template class CRS<double>;


template <class fp_type>
std::vector<fp_type> matVec(CRS<fp_type> &mat, std::vector<fp_type> &vector) {
    this->_ia
    this->_ja
    this->_vals

    std::vector<fp_type> result;
    int ncols = mat.getNCols();
    int nrows = mat.getNRows();
    int i,j,N;
    N = nrows;
    for (k = 0; k < N; k = k + 1)
       result[i] = 0;

	for (i = 0; i < N; i = i + 1)
	 {  
		for (k = ia[i]; k < ia[i+1]; k = k + 1)
      	{  
        	result[i] = result[i] + vals[k]*vector[ja[k]];
      }  
    }
	return result; 
}

}
