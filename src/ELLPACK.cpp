#include <map>
#include <utility>
#include <vector>

#include "ELLPACK.hpp"

namespace spmv
{

double ELLPACK::getData(int i, int j){
	double aij = 0;
	for (int k = 0;k<_ellcols;k++){
		if (_index_array[i][k] == j){
			aij += _vals_array[i][k];
			break;
		}	
	}
	return aij;
}
template <class fp_type>
void ELLPACK<fp_type>::setCoefficients(const std::map< std::pair<size_t,size_t> , fp_type > &buildCoeff){

}

template <class fp_type>
void ELLPACK<fp_type>::matVec(const std::vector<fp_type> &x, std::vector<fp_type> &b) const{
	if ((*this)._nrows != b.size){
                std::cerr << "[ELLPACK matVec] Dimension mismatch: A, b (Ax=b)\n";
                exit(EXIT_FAILURE);
        }
	if ((*this)._ncols != x.size){
                std::cerr << "[ELLPACK matVec] Dimension mismatch: A, x (Ax=b)\n";
                exit(EXIT_FAILURE);
        }

	for (int i = 0;i<_ellrows;i++){
		b[i] = 0;
		for (int j=0;j<_ellcols;j++){
			if (_vals_array[i,j] != 0){
				b[i] += _vals_array[i,j]*x[j];
			}
		}
	}

}

template <class fp_type>
void ELLPACK<fp_type>::getELLPACK(std::vector<fp_type> &vals, std::vector<std::vector<size_t> > &ja, size_t &maxnz_row) const{

}

template class ELLPACK<float>;
template class ELLPACK<double>;
}
