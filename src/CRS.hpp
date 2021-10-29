#ifndef _CRS_MATRIX_
#define _CRS_MATRIX_

#include <map>
#include <utility>
#include <vector>
#include "SparseMatrix.hpp"

namespace spmv
{
template <class fp_type>
class CRS : public SparseMatrix<fp_type>
{
    private:
        std::vector<fp_type> _vals;
        std::vector<size_t> _ia;
        std::vector<size_t> _ja;
        int nrows;
        int ncols;

    public:
        //This is the constructor
        CRS(const size_t nrows, const size_t ncols):SparseMatrix<fp_type>(nrows, ncols){};

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
            Function : getCRS
                Gets sparse matrix in CRS format
            
            Parameters
            ----------
            vals : values in the matrix, size _nnz
            ja   : column indices, size _nnz
            ia   : row indices, size _nrows + 1
        */
        void getCRS(std::vector<fp_type> &vals, std::vector<size_t> &ia, std::vector<size_t> &ja) const override;

        /*
            Function : getValues
                Get non zero values in the matrix as a vector
            
            Parameters
            ----------
            None
        */
        std::vector<fp_type> getValues();

        /*
            Function : getRowsIndices
                Get non zero values rows indices
            
            Parameters
            ----------
            None
        */
        std::vector<size_t> getRowsIndices();

        /*
            Function : getColsIndices
                Get non zero values columns indices
            
            Parameters
            ----------
            None
        */
        std::vector<size_t> getColsIndices();

        int getNRows();
        int getNCols();

};
}

#endif
