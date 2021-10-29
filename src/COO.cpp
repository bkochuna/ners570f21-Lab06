#include "COO.hpp"
#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>

namespace spmv {

template <class fp_type>
void COO<fp_type>::setCoefficients(
    const std::map<std::pair<size_t, size_t>, fp_type> &buildCoeff) {}

template <class fp_type>
void COO<fp_type>::getCOO(std::vector<fp_type> &vals,
                          std::vector<size_t> &idx_col,
                          std::vector<size_t> &idx_row) const {}

template class COO<float>;
template class COO<double>;

} // namespace spmv