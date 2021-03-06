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
        std::vector<std::vector<fp_type> > _vals;
        std::vector<size_t> _ia;
        std::vector<size_t> _ja;

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
};
}

#endif
