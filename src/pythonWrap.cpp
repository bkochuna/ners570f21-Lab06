#include "pythonWrap.hpp"

PYBIND11_MODULE(SpMVpy, m) {
  // Only export float libraries?
  py::class_<spmv::SparseMatrix<float>, PySparseMatrix<float>>(m,
                                                               "SparseMatrix")
      .def("setCoefficients", &spmv::SparseMatrix<float>::setCoefficients)
      .def("getnRows", &spmv::SparseMatrix<float>::getnRows)
      .def("getnCols", &spmv::SparseMatrix<float>::getnCols)
      .def("getnNZ", &spmv::SparseMatrix<float>::getnNZ);

  py::class_<spmv::COO<float>, spmv::SparseMatrix<float>>(m, "COO")
      .def(py::init<size_t, size_t>())
      .def("setCoefficients", &spmv::COO<float>::setCoefficients)
      .def("getCOO", &spmv::COO<float>::getCOO);

  py::class_<spmv::BCRS<float>, spmv::SparseMatrix<float>>(m, "BCRS")
      .def(py::init<size_t, size_t>())
      .def("setCoefficients", &spmv::BCRS<float>::setCoefficients)
      .def("getBCRS", &spmv::BCRS<float>::getBCRS);

  py::class_<spmv::CRS<float>, spmv::SparseMatrix<float>>(m, "CRS")
      .def(py::init<size_t, size_t>())
      .def("setCoefficients", &spmv::CRS<float>::setCoefficients)
      .def("getCRS", &spmv::CRS<float>::getCRS);

  py::class_<spmv::ELLPACK<float>, spmv::SparseMatrix<float>>(m, "ELLPACK")
      .def(py::init<size_t, size_t>())
      .def("setCoefficients", &spmv::ELLPACK<float>::setCoefficients)
      .def("getELLPACK", &spmv::ELLPACK<float>::getELLPACK);

  py::class_<spmv::JDS<float>, spmv::SparseMatrix<float>>(m, "JDS")
      .def(py::init<size_t, size_t>())
      .def("setCoefficients", &spmv::JDS<float>::setCoefficients)
      .def("getJDS", &spmv::JDS<float>::getJDS);
}