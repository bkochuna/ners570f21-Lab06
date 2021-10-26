#ifndef _JDS_MATRIX_
#define _JDS_MATRIX_

#include <map>     //for using map (like a Python dictionary)
#include <utility> //for using pair
#include <vector>
#include "SparseMatrix.hpp"

namespace spmv
{
template <class fp_type>
class JDS : public SparseMatrix<fp_type>
{
    private:
       std::vector<size_t> _perm;
       std::vector<fp_type> _jdiag;
       std::vector<size_t> _col_ind;
       std::vector<size_t> _jd_ptr;
       
    public:
        //This is the constructor
        JDS(const size_t nrows, const size_t ncols):SparseMatrix<fp_type>(nrows, ncols){};


       /*
          Function : setCoefficients
            Builds a sparse matrix 

          Parameters
          ----------
          buildCoefficient
            a binary tree containing the [i, j] coordinates of non zero entries in the key and values in the values.

        */
        void setCoefficients(const std::map< std::pair<size_t,size_t> , fp_type > &buildCoeff) override ;

        /*
          Function : getJDS
            Gets sparse matrix in JDS format

            Parameters
            ----------
          perm    : permutation array that reorders the rows, size _nrows
          jdiag   : array containing jagged diagonals in succession, size non_zero in first row
          col_ind : array containing coresponding column indices, size non_zero in first row
          jd_ptr  : pointer array pointing to the beginning of each jagged diagonal, size nn_zero in first row
        */
        void getJDS(std::vector<size_t> &perm, std::vector<fp_type> &jdiag, std::vector<size_t> &col_ind, std::vector<size_t> &jd_ptr) const override;

};
   
}

#endif
