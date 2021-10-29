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

  class_<spmv::BCRS<float>, bases<spmv::SparseMatrix<float>>>(
      "BCRS", init<size_t, size_t>())
      .def("setCoefficients", &spmv::BCRS<float>::setCoefficients)
      .def("getBCRS", &spmv::BCRS<float>::getBCRS);

  class_<spmv::CRS<float>, bases<spmv::SparseMatrix<float>>>(
      "CRS", init<size_t, size_t>())
      .def("setCoefficients", &spmv::CRS<float>::setCoefficients)
      .def("getCRS", &spmv::CRS<float>::getCRS);

  class_<spmv::ELLPACK<float>, bases<spmv::SparseMatrix<float>>>(
      "ELLPACK", init<size_t, size_t>())
      .def("setCoefficients", &spmv::ELLPACK<float>::setCoefficients)
      .def("getELLPACK", &spmv::ELLPACK<float>::getELLPACK);

  class_<spmv::JDS<float>, bases<spmv::SparseMatrix<float>>>(
      "JDS", init<size_t, size_t>())
      .def("setCoefficients", &spmv::JDS<float>::setCoefficients)
      .def("getJDS", &spmv::JDS<float>::getJDS);
}