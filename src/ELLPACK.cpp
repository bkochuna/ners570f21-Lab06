#include <map>
#include <utility>
#include <vector>

#include "ELLPACK.hpp"

namespace spmv {
template <class fp_type>
void ELLPACK<fp_type>::setCoefficients(
    const std::map<std::pair<size_t, size_t>, fp_type> &buildCoeff) {}

template <class fp_type>
void ELLPACK<fp_type>::matVec(const std::vector<fp_type> &x,
                              std::vector<fp_type> &b) const {}

template <class fp_type>
void ELLPACK<fp_type>::getELLPACK(std::vector<fp_type> &vals,
                                  std::vector<std::vector<size_t>> &ja,
                                  size_t &maxnz_row) const {}

template class ELLPACK<float>;
template class ELLPACK<double>;
} // namespace spmv
