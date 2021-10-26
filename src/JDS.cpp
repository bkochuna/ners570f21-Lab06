#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>
#include "JDS.hpp"

namespace spmv
{
template <class fp_type>
void JDS<fp_type>::setCoefficients(const std::map< std::pair<size_t,size_t> , fp_type > &buildCoeff) {

}

template <class fp_type>
void JDS<fp_type>::getJDS(std::vector<size_t> &perm, std::vector<fp_type> &jdiag, std::vector<size_t> &col_ind, std::vector<size_t> &jd_ptr) const{
    
}

template class JDS<float>;
template class JDS<double>;

}
