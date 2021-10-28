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

template class CRS<float>;
template class CRS<double>;


template <class fp_type>
std::vector<fp_type> vecMult(CRS<fp_type> &mat, std::vector<fp_type> &vec) {
    
}

}
