#ifndef _SPARSE_MATRIX_
#define _SPARSE_MATRIX_

#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair

namespace spmv
{
template <class fp_type>
class SparseMatrix
{
     //private:

     protected:
       size_t _nrows;
       size_t _ncols;
       size_t _nz    = 0;

       std::map< std::pair<size_t,size_t> , fp_type > _buildCoeff;        
     public:
        //This is the constructor
        SparseMatrix(const size_t nrows, const size_t ncols):_nrows(nrows), _ncols(ncols), _nz(0) {};

       /*
          Function : setCoefficients
            Builds a sparse matrix 

          Parameters
          ----------
          buildCoefficient
            a binary tree containing the [i, j] coordinates of non zero entries in the key and values in the values.

        */
        virtual void setCoefficients(const std::map< std::pair<size_t,size_t> , fp_type > &buildCoeff) = 0;

        /* 
          Function : matVec
            Preforms matrix vector multiplication

          Parameters
          ----------
          x : array of length equal to the number of columns in the matrix to multiply
          b : array of length equal to the number of columns in the matrix that is the result of the multiplication

        */
        virtual void matVec(const fp_type * const x,  fp_type * const b) const = 0;

      /*
        Function : getCOO
          Gets the Sparse matrix in COO format

        Parameters
        ----------
        vals : the values in the matrix, size nnz
        idx_col : column indices for the values, size nnz
        idx_row : row indices for the values, size nnz
        */
        virtual void getCOO(fp_type * const vals, size_t * const idx_col, size_t * const idx_row) const = 0;

        /*
          Function : getELLPACK
            Gets the sparse matrix in ELLPACK format
          
          Parameters
          ----------
          vals      : the values in the matrix, size nnz
          ja        : a 2d array of size _nrows by maxnz_row that contains column indices
          maxnz_row : size of second dimension for ja
        */
        virtual void getELLPACK(fp_type * const vals, size_t ** const ja, size_t &maxnz_row) const = 0;

        /*
          Function : getCRS
            Gets sparse matrix in CRS format
          
          Parameters
          ----------
          vals : values in the matrix, size _nnz
          ja   : column indices, size _nnz
          ia   : row indices, size _nrows + 1
        */
        virtual void getCRS(fp_type * const vals, size_t * const ia, size_t *const ja) const = 0;

        /*
          Function : getBCRS
            Gets sparse matrix in BCRS format
          
          Parameters
          ----------
          vals : non-zero blocks in (block) row-wise fashion, size nblk by block size by block size
          ia   : pointer array that points to the beginning of each block row in val and ja, size _nrows + 1
          ja   : column indices, size _nnz
          nblk : number of non-zero blocks
        */
        virtual void getBCRS(fp_type *** const vals, size_t * const ia, fp_type * const ja, size_t &nblk) const = 0;

        /*
          Function : getJDS
            Gets sparse matrix in BCRS format

            Parameters
            ----------
          perm    : permutation array that reorders the rows, size _nrows
          jdiag   : array containing jagged diagonals in succession, size non_zero in first row
          col_ind : array containing coresponding column indices, size non_zero in first row
          jd_ptr  : pointer array pointing to the beginning of each jagged diagonal, size nn_zero in first row
        */
        virtual void getJDS(fp_type * const perm, fp_type * const jdiag, fp_type * const col_ind, fp_type ** const jd_ptr) const = 0;

};
   
}

#endif
