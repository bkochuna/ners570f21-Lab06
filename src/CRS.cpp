#include "CRS.hpp"
#include <map>
#include <utility>
#include <vector>

namespace spmv {
template <class fp_type>
void CRS<fp_type>::setCoefficients(
    const std::map<std::pair<size_t, size_t>, fp_type> &buildCoeff) {}

template <class fp_type>
void CRS<fp_type>::getCRS(std::vector<fp_type> &vals, std::vector<size_t> &ia,
                          std::vector<size_t> &ja) const {}

template class CRS<float>;
template class CRS<double>;

} // namespace spmv
