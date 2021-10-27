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
    
    int nz = 0
    &ncols = *(&ia + 1) - ia - 1;
    &nrows = *(&ia + 1) - ia - 1;
    for (i = 1; i<=&ncols; i=i+1) {//row
        for (j = 1; j<=&ncols; j=j+1) { // coloumn
            if ((&ja[nz] == j) && (nz <= &ia[i])) {
                A[i][j] = &vals[&nz];
                nz = nz+1;
            }
            else {
                A[i][j] = 0;
            }
        }
    }
    &nz = nz

}

template class CRS<float>;
template class CRS<double>;

}
