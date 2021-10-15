#include "SparseMatrix.hpp"

using namespace spmv;

int main() {
  int i;

  //Define a scoping unit
  std::cout << "Before  scoping unit" << std::endl;
  {
    SparseMatrix<double> A_double(10,10); //Call the constructor
    SparseMatrix<float> A_float(10,10); 
    std::cout << "After variable definition" << std::endl;
  } // Destructor will be called here
  std::cout << "After scoping unit" << std::endl;

  return 0;
}
