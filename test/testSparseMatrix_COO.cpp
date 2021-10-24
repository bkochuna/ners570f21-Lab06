#include <iostream>
#include <cmath>

//#ifndef _SPARSE_MATRIX
//#define _SPARSE_MATRIX
//#include "src/SparseMatrix.hpp"
//#include "src/SparseMatrix.cpp"
//#endif

//#ifndef _SPARSE_MATRIX_COO_
//#define _SPARSE_MATRIX_COO_
#include "../src/SparseMatrix_COO.hpp"
//#include "src/SparseMatrix_COO.cpp"
//#endif


void pr2(){
	//problem 2
	printf("Hello from problem2\n");
	size_t Nx = 6;
	size_t Ny = 6;
	size_t n = 8;
	size_t rows[] = {0,0,1,1,2,2,2,3};
	size_t cols[] = {0,1,1,3,2,3,4,5};
	double aij[] = {10,20,30,40,50,60,70,80};
	spmv::SparseMatrix_COO<double> sp(Nx,Ny);
	printf("Sparse Matrix %zux%zu\n",sp.test,sp.test);
	int s = sizeof(aij)/sizeof(aij[0]);
	printf("Size of aij is %i\n",s);
	sp.setCoefficients(rows,cols,aij,s);
	//printf("Sparse Matrix nnz = %.2f\n",sp.[0]);
	//sp.assemble(); //setCoefficients calls assemble()
	//s = sizeof(sp.A)/sizeof(sp.A[0]);
	s = sp.A.size();
	printf("size of A = %i\n",s);
	for(int k=0;k<s;k++){std::cout << "A["<<k<<"] = " << sp.A[k] << std::endl;}
	double x[n] = {1,1,1,1,1,1,1,1};	
	double b[n] = {0};
	std::cout<<std::endl;
	sp.matVec(x,b,n);
	for(int k=0;k<n;k++){std::cout << "b["<<k<<"] = " << b[k] << std::endl;}
	double test1 = sp.getCoefficient(1,1);
	double test2 = sp.getCoefficient(1,4);
	std::cout << "yes="<<test1<<std::endl;
	std::cout << "no="<<test2<<std::endl;


} //end of pr()

int main(){pr2();return 0;}
