#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include "JDS.hpp"

namespace spmv
{
template <class fp_type>
JDS<fp_type>::~JDS(){

}

template <class fp_type>
JDS<fp_type>::JDS(const JDS<fp_type> &other) : SparseMatrix<fp_type>(other._nrows, other._ncols){

}

template <class fp_type>
JDS<fp_type> &JDS<fp_type>::operator=(const JDS<fp_type> &other) {
    return *this;
}

template <class fp_type>
void JDS<fp_type>::setCoefficients(const std::map< std::pair<size_t,size_t> , fp_type > &buildCoeff) {

}

template <class fp_type>
void JDS<fp_type>::matVec(const fp_type * const x,  fp_type * const b) const{

}

template <class fp_type>
void JDS<fp_type>::getCOO(fp_type * const vals, size_t * const idx_col, size_t * const idx_row) const {

}

template <class fp_type>
void JDS<fp_type>::getELLPACK(fp_type * const vals, size_t ** const ja, size_t &maxnz_row) const {

}

template <class fp_type>
void JDS<fp_type>::getCRS(fp_type * const vals, size_t * const ia, size_t *const ja)  const {

}

template <class fp_type>
void JDS<fp_type>::getBCRS(fp_type *** const vals, size_t * const ia, fp_type * const ja, size_t &nblk)  const {

}

template <class fp_type>
void JDS<fp_type>::getJDS(fp_type * const perm, fp_type * const jdiag, fp_type * const col_ind, fp_type ** const jd_ptr) const {

}

template class JDS<float>;
template class JDS<double>;

}
