#ifndef _PYTHON_WRAP_
#define _PYTHON_WRAP_
#include "BCRS.hpp"
#include "COO.hpp"
#include "CRS.hpp"
#include "ELLPACK.hpp"
#include "JDS.hpp"
#include <boost/python.hpp>
#include <map>

using namespace boost::python;

template <class fp_type>
struct SparseMatrixWrap : spmv::SparseMatrix<fp_type>,
                          wrapper<spmv::SparseMatrix<fp_type>> {
  void setCoefficients(
      const std::map<std::pair<size_t, size_t>, fp_type> &buildCoeff) {
    this->get_override("setCoefficients")(buildCoeff);
  }
};

#endif