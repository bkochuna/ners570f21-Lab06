#include "BCRS.hpp"
#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>

namespace spmv {
template <class fp_type>
void BCRS<fp_type>::setCoefficients(
    const std::map<std::pair<size_t, size_t>, fp_type> &buildCoeff) {}

template <class fp_type>
void BCRS<fp_type>::getBCRS(
    std::vector<std::vector<std::vector<fp_type>>> &vals,
    std::vector<size_t> &ia, std::vector<size_t> &ja, size_t &nblk) const {}

template class BCRS<float>;
template class BCRS<double>;

} // namespace spmv
