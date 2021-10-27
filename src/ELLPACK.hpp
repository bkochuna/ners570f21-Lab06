#ifndef _ELLPACK_
#define _ELLPACK_

#include <map>
#include <utility>
#include <vector>

#include "SparseMatrix.hpp"

namespace spmv
{
template <class fp_type>
class ELLPACK : public SparseMatrix<fp_type>
{
    private:
        std::vector<fp_type> _vals;
        std::vector<std::vector<size_t> > _ja;
        size_t _maxnz_row;

    public:
        //This is the constructor
        ELLPACK(const size_t nrows, const size_t ncols):SparseMatrix<fp_type>(nrows, ncols), _maxnz_row(0) {};

        /*
            Function : setCoefficients
                Builds a sparse matrix 

            Parameters
            ----------
            buildCoefficient
                a binary tree containing the [i, j] coordinates of non zero entries in the key and values in the values.
        */
        void setCoefficients(const std::map< std::pair<size_t,size_t> , fp_type > &buildCoeff) override;

        /*
            Function : matVec
                Preforms matrix vector multiplication

            Parameters
            ----------
            x : array of length equal to the number of columns in the matrix to multiply
            b : array of length equal to the number of columns in the matrix that is the result of the multiplication
        */
        void matVec(const std::vector<fp_type> &x, std::vector<fp_type> &b) const override;

        /*
            Function : getELLPACK
                Gets the sparse matrix in ELLPACK format

            Parameters
            ----------
            vals      : the values in the matrix, size nnz
            ja        : a 2d array of size _nrows by maxnz_row that contains column indices
            maxnz_row : size of second dimension for ja
        */
        void getELLPACK(std::vector<fp_type> &vals, std::vector<std::vector<size_t> > &ja, size_t &maxnz_row) const override;

};
}
#endif
