#ifndef _PYTHON_WRAP_
#define _PYTHON_WRAP_
#include "BCRS.hpp"
#include "COO.hpp"
#include "CRS.hpp"
#include "ELLPACK.hpp"
#include "JDS.hpp"
// #include "SparseMatrix.hpp"
#include <map>
#include <pybind11/pybind11.h>

namespace py = pybind11;

template <class fp_type>
class PySparseMatrix : public spmv::SparseMatrix<fp_type> {
public:
  /* Inherit the constructors */
  using spmv::SparseMatrix<fp_type>::SparseMatrix;

  /* Trampoline (need one for each virtual function) */
  void setCoefficients(
      const std::map<std::pair<size_t, size_t>, fp_type> &buildCoeff) override {
    PYBIND11_OVERRIDE_PURE(void,                        /* Return type */
                           spmv::SparseMatrix<fp_type>, /* Parent class */
                           setCoefficients, /* Name of function in C++ (must
                                               match Python name) */
                           buildCoeff       /* Argument(s) */
    );
  }
};

#endif