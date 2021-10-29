#include "pythonWrap.hpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(SpMVpy) {
  // Only export float libraries?
  class_<SparseMatrixWrap<float>, boost::noncopyable>("SparseMatrix", no_init)
      .def("setCoefficients",
           pure_virtual(&spmv::SparseMatrix<float>::setCoefficients))
      .def("getnRows", &spmv::SparseMatrix<float>::getnRows)
      .def("getnCols", &spmv::SparseMatrix<float>::getnCols)
      .def("getnNZ", &spmv::SparseMatrix<float>::getnNZ);

  class_<spmv::COO<float>, bases<spmv::SparseMatrix<float>>>(
      "COO", init<size_t, size_t>())
      .def("setCoefficients", &spmv::COO<float>::setCoefficients)
      .def("getCOO", &spmv::COO<float>::getCOO);
}