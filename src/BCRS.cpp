#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include "BCRS.hpp"

namespace spmv
{
template <class fp_type>
BCRS<fp_type>::~BCRS(){

}

template <class fp_type>
BCRS<fp_type>::BCRS(const BCRS<fp_type> &other) {

}

template <class fp_type>
BCRS<fp_type> &BCRS<fp_type>::operator=(const BCRS<fp_type> &other) {

}

template <class fp_type>
void BCRS<fp_type>::setCoefficients(const std::map< std::pair<size_t,size_t> , fp_type > &buildCoeff) {

}

template <class fp_type>
void BCRS<fp_type>::matVec(const fp_type * const x,  fp_type * const b) const{

}

template <class fp_type>
void BCRS<fp_type>::getCOO(fp_type * const vals, size_t * const idx_col, size_t * const idx_row) const {

}

template <class fp_type>
void BCRS<fp_type>::getELLPACK(fp_type * const vals, size_t ** const ja, size_t &maxnz_row) const {

}

template <class fp_type>
void BCRS<fp_type>::getCRS(fp_type * const vals, size_t * const ia, size_t *const ja)  const {

}

template <class fp_type>
void BCRS<fp_type>::getBCRS(fp_type *** const vals, size_t * const ia, fp_type * const ja, size_t &nblk)  const {

}

template <class fp_type>
void BCRS<fp_type>::getJDS(fp_type * const perm, fp_type * const jdiag, fp_type * const col_ind, fp_type ** const jd_ptr) const {

}

}
