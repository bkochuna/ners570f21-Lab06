#ifndef _SPARSE_MATRIX_COO_
#define _SPARSE_MATRIX_COO_

#include <iostream>
#include <cstddef>
#include <cstddef> //for size_t
#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>
#include "SparseMatrix.hpp"
//#include "SparseMatrix.cpp"

//Derived Class
namespace spmv
{
template <class fp_type>
class SparseMatrix_COO: public SparseMatrix<fp_type> {
	//private:
		//
     protected:
       size_t _nrows = 0;
       size_t _ncols = 0;
       size_t _nz    = 0;

       std::map< std::pair<size_t,size_t> , fp_type > _buildCoeff;
       std::map< std::pair<size_t,size_t> , fp_type > _irows;
       std::map< std::pair<size_t,size_t> , fp_type > _jcols;
     public:
        //This is the constructor
        SparseMatrix_COO(const size_t nrows, const size_t ncols);
       ~SparseMatrix_COO(); //This is the destructor
		//attributes:
		size_t test = 0;
		/*
		size_t* irows,*jcols;
		fp_type* A;
		*/
		std::vector<size_t> irows;
		std::vector<size_t> jcols;
		std::vector<fp_type> A;
		
		//methods:
		//sets coefficient of sparse matrix one at a time
		void setCoefficient(const size_t row, const size_t col, fp_type aij);
		void setCoefficients(const size_t row[], const size_t col[], const fp_type A[], const size_t N);
		void assemble();
		void matVec(fp_type x[], fp_type b[],size_t N);
		fp_type getCoefficient(const size_t row, const size_t col);
}; //endof COO class
} //endof namespace spmv
#endif 
