// BCRS_solo.hpp
// Created by N.L. - Oct 23 2021

// Initially planned to set up a derived class BCRSarrays based on the base class SparseMatrix
// However, because the functionality in SparseMatrix is not ready yet, 
// we decided to set up an independent BCRS class first
// so that we can implement this module and do some simple testing

//#include "SparseMatrix.hpp"
//#include "SparseMatrix.cpp"

#ifndef _bcrs_h //prevent including the header file multiple times
#define _bcrs_h
#include <iostream>
#include <cstddef>
#include <map>
#include <utility>

namespace spmv_bcrs{
    template <class fp_type>
		class BCRSarrays
		{
			protected:
				size_t _nrows = 0;
				size_t _ncols = 0;
				size_t _nz    = 0;
				size_t _nblk = 0; /*size of blocks*/

				double *aij;
				int *ia;
				int *ja;

				//	std::map< std::pair<size_t,size_t> , fp_type > _buildCoeff;

			public:
				BCRSarrays(const size_t nrows, const size_t ncols);
				~BCRSarrays();
				//	BCRSarrays* CreateBCRS(SparseMatrix *m);
				int countBlocks(double** M, int nrows, int ncols);
				//int getNumNonZero(double** M, int row, int col);	
				void PrintBCRS(BCRSarrays *c);
				void MultiplyBCRS(BCRSarrays *c, double *x, double *result);
				void createBCRSArrays(double **M, int row, int col);
		};

	template class BCRSarrays<float>;
	template class BCRSarrays<double>;

	template <class fp_type>
		BCRSarrays<fp_type>::BCRSarrays(const size_t nrows, const size_t ncols) :
			_nrows(nrows), _ncols(ncols)
	{
					aij = NULL;
					ia = NULL;
					ja = NULL;
                                        _nrows = nrows;
                                        _ncols = ncols;
					std::cout << "BCRS array created! Dim = " << nrows << "," << ncols << "\n";

		std::cout << "Called BCRS Constructor" << std::endl;
		//Intent of this routine is to create an instance of the class
	}

	template <class fp_type>
		BCRSarrays<fp_type>::~BCRSarrays(){
					delete[] aij;
					delete[] ia;
					delete[] ja;
					std::cout << "BCRS array deconstructed!" << "\n";

			std::cout << "Called BCRS Destructor" << std::endl;
			//Intent of this routine is to cleanup the object and
			//any memory associated with it.
		}


	template <class fp_type>
		void BCRSarrays<fp_type> :: createBCRSArrays(double **M, int row, int col) {
                        //std :: cout << 1 << std :: endl;
			int numNonZero = 0;
			for (int i = 0; i < row; i ++) {
				for (int j = 0; j < row; j ++) {
					if (M[i][j] != 0) {
						numNonZero += 1;
					}
				}
			}
                        //this -> _nrows = row;
                        //this -> _ncols = col;
			this -> aij = new double [numNonZero];
			this -> ia = new int[numNonZero];
			this -> ja = new int[col];
			int index = 0;
			int index2 = 0;
			bool insert = true;

			for (int i = 0; i < row; i ++) {
				insert = true;
				for (int j = 0; j < col; j ++) {
					if(M[i][j] != 0.0) {
						aij[index] = M[i][j];
						ia[index] = j;
						if (insert == true) {

							ja[index2] = index;
							index2 += 1;
							insert = false;
						}
						index += 1;
					}
				}
			}
		
               std :: cout << "aij is :" << std :: endl;
               for (int i = 0; i < numNonZero; i ++) {
                std :: cout << aij[i] << " ";
               }
               std :: cout << std :: endl;
               std :: cout <<"ia is: " <<std :: endl;
               for (int i = 0; i < numNonZero; i ++) {
                 std :: cout << ia[i] << " ";
               }
               std :: cout << std :: endl;
               std :: cout <<"ja is:" <<std :: endl;
               for (int i = 0; i < col; i ++) {
                 std :: cout << ja[i] << " " ;
               }
               std :: cout << std :: endl;
}

template <class fp_type> 
int BCRSarrays<fp_type> :: countBlocks(double** M, int nrows, int ncols) {
    std :: cout << "call countBlocks Function" << std :: endl;
    int i, j, nblocks = 0;
   // int nrows = my_m->nrows;
   // int ncols = my_m->ncols;
   // double** mal = M;
   // int nrows = this -> _nrows;
   // int ncols = this ->  _ncols;
    for (i = 0; i < nrows; ++i) {
        for (j = 0; j < ncols; ++j) {
            if (M[i][j] != 0) {
                if (j == 0) {
                    nblocks++;
                } else if ((j != 0) && (M[i][j-1] == 0)) {
                    nblocks++;
                }
            }
        }
    }
    _nblk = nblocks;
  return nblocks;
}

}
#endif
