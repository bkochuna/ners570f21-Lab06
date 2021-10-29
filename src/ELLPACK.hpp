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
        double* _vals_array;
        double* _index_array;
        int _ellrows;
	int _ellcols;

    public:
        //Constructor from array
	template<unsigned int rows, unsigned int cols>
        ELLPACK(double (&a)[rows][cols]):SparseMatrix<fp_type>(rows, cols) {
		int maxcols = 0;
		int nrows = 0;
		int nzrow = 0;
		for (int i=0; i<_nrows;i++){
			nzrow = 0;
			for (int j=0; j<_ncols;j++){
				if (a[i][j] != 0){
					nzrow += 1;

				}
			}
			if (nzrow>0){
				nrows += 1;
				if (nzrow > maxcols){
					maxcols = nzrow;
				}
			}
		}		
		_ellrows = nrows;
		_ellcols = maxcols;
		_vals_array = new double[nrows][maxcols];
		_index_array = new double[nrows][maxcols];
		for (int i=0; i<_nrows;i++){
			nzrow = 0;
			for (int j=0; j<_ncols;j++){
				_vals_array[i,nzrow] = 0;
				_index_array[i,nzrow] = 0;
				if (a[i][j] != 0){
					_vals_array[i,nzrow] = a[i,j];
					_index_array[i,nzrow] = j;
					nzrow += 1;	
				}else{
				}
			}
		}
		
		
	};
	
	// Use paranthesis operator to access elements in the matrix
	double& operator()(int i, int j){
		return getData(i,j); }
	double operator()(int i, int j) const {
		return getData(i,j); }	

	/*
	    Function : getData
   		get matrix data from the ELLPACK format given indices of the overall matrix
    	
	    Paramters
	    --------
		i, j = row, column index of the element in overall matrix		

	*/
	double getData(int i, int j);


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
