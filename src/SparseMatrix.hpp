#ifndef _SPARSE_MATRIX_
#define _SPARSE_MATRIX_

#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>

namespace spmv
{
template <class fp_type>
class SparseMatrix
{
     protected:
       size_t _nrows;
       size_t _ncols;
       size_t _nz    = 0;

       std::map< std::pair<size_t,size_t> , fp_type > _buildCoeff;        
     public:
        //Default constructor
        SparseMatrix(): _nrows(0), _ncols(), _nz(0) {}
	
	//Constructor with memory allocation	
	SparseMatrix(const size_t nrows, const size_t ncols): SparseMatrix() {
		_nrows = nrows;
	       	_ncols = ncols;
	       	_nz = 0;

	}
       /*
          Function : setCoefficients
            Builds a sparse matrix 

          Parameters
          ----------
          buildCoefficient
            a binary tree containing the [i, j] coordinates of non zero entries in the key and values in the values.

        */

        size_t getnRows();

        /*
          Function : getnCols
            Returns the number of cols in the matrix

          Returns
          ----------
            _ncols
        */
        size_t getnCols();

        /*
          Function : getnNZ
            Returns the number of non-zeros in the matrix

          Returns
          ----------
            _nz
        */
        size_t getnNZ();

};
   
}

#endif
