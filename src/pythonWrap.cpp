#include <boost/python.hpp>
#include "hello.hpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(SpMVpy)
{
  def("hello", spmv::hello);
}