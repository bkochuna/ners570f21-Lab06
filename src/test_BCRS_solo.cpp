#include "BCRS_solo.hpp"
#include <iostream>
using namespace spmv_bcrs;

//int countBlocks(){
// purpose: return the number of blocks by finding location of zero entries
 //   int i, j, nblocks = 0;
/*
 *  int nrows = c->nrows;
 *  int ncols = c->ncols;
 *  double** mal = c->aij;
 *
 *  for (i = 0; i < nrows; ++i) {
 *    for (j = 0; j < ncols; ++j) {
 *      if (mal[i][j] != 0) {
 *        // is this the first element in the block?
 *          if (j == 0) {
 *            nblocks++;
 *          } else if ((j != 0) && (mal[i][j-1] == 0)) {nblocks++;}
 *      }
 *    }
 }*/
//    return nblocks;
//}
/*
int main() {
  int i,j,nbk = 0;

  //Define a scoping unit
  std::cout << "Before scoping unit" << std::endl;
  {
  BCRSarrays<double> B_double(10,10); //Call the constructor
  BCRSarrays<float> B_float(10,10);
  nbk = countBlocks();
  std::cout <<"number of blocks = " << nbk <<std::endl;
  std::cout << "After variable definition" << std::endl;
  }
  // Destructor will be called here (inexplicitly!)
  std::cout << "After scoping unit" << std::endl;
  return 0;
}
*/
int main() {
  int row = 3;
  int col = 3;
  double **M = new double* [row];
  for (int i = 0; i < row; i ++) {
    M[i] = new double [row];
  }
  
  for (int i = 0; i < row; i ++) {
    for (int j = 0; j < col; j ++) {
      if (i == j) {
        M[i][j] = 0;
      }
      else {
       M[i][j] = 2*2;
      }
    }
  }
  
  
  
  BCRSarrays<double> B(10,10);
  B.createBCRSArrays(M,row,col);
  B.countBlocks(M, row, col);
  for (int i = 0; i < row; i ++) {
    delete[] M[i];
  }
  delete[] M;
  return 0;
}
