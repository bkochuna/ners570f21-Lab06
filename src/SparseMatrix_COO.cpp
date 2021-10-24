#include "SparseMatrix_COO.hpp"
#include <vector>


namespace spmv
{
template <class fp_type>
SparseMatrix_COO<fp_type>::SparseMatrix_COO(const size_t nrows, const size_t ncols) : SparseMatrix<fp_type>(nrows,ncols)
{
    std::cout << "Called SparseMatrix COO Constructor" << std::endl;
    //Intent of this routine is to create an instance of the class
    // If you're not familiar with C++ this is what you might do
    this->_nrows = nrows;
    this->_ncols = ncols;
	printf("Sparse Matrix COO %zux%zu\n",_nrows,_ncols);
}

template <class fp_type>
SparseMatrix_COO<fp_type>::~SparseMatrix_COO() {
    std::cout << "Called SparseMatrix COO Destructor" << std::endl;
    //Intent of this routine is to cleanup the object and
    //any memory associated with it.
}

template <class fp_type>
void SparseMatrix_COO<fp_type>::setCoefficient(const size_t row, const size_t col, const fp_type aij) {
	std::cout << "Called SparseMatrix COO SetCoefficient" << std::endl;
	//Set aij one at a time
	auto s = std::make_pair(row,col);
	this->_buildCoeff[ s ] = aij;
	this->_jcols[ s ] = col;
	this->_irows[ s ] = row;
}
template <class fp_type>
void SparseMatrix_COO<fp_type>::setCoefficients(const size_t row[], const size_t col[], const fp_type A[], const size_t N) {
		std::cout << "Called SparseMatrix COO SetCoefficient" << std::endl;
	//set A[] all in one command. Must pass in row[] with all i vaules
	//and col[] with all j values of non-zero entries
	for(int k=0;k<N;k++){
		setCoefficient(row[k],col[k],A[k]);
		printf("%i\n",k);
	}
	assemble();
}

template <class fp_type>
void SparseMatrix_COO<fp_type>::assemble() {
	std::cout << "Called SparseMatrix COO assemble" << std::endl;
	//creates sparse matrix A to be returned
	//irows and jcols for index matrices
	//and determines the number of non-zeros _nz
	size_t nnz = 0;
	nnz = _buildCoeff.size();
	this->_nz = nnz;
	printf("_nz = %zu\n",_nz);
	printf("nnz = %zu\n",nnz);
	
	//std::vector<std::pair<size_t,size_t>> A = (_buildCoeff.begin(), _buildCoeff.end());

	//
	irows.resize(_nz);
	jcols.resize(_nz);
	A.resize(_nz);

	int k = 0;
	for(int i=0;i<_nrows;i++){
		for(int j=0;j<_ncols;j++){
			auto s = std::make_pair(i,j);
			if (_buildCoeff.find(s) != _buildCoeff.end() ){
				jcols[k] = _jcols[s];
				irows[k] = _irows[s];
				A[k]	 = _buildCoeff[s];
				k++;
			}
		}
	}


	//print mat to screen for check
	//diplay sparse A values
	int s = A.size();
	printf("\nA[%i] = < ",s); 
	for(int k=0;k<s;k++){
			std::cout << A[k] << " ";
	}
	printf(">\n");

	//display irows
	printf("\nirows[%i] = < ",s); 
	for(int k=0;k<s;k++){
		printf("%zu ",irows[k]);
	}
	printf(">\n");
	
	//displays jcols
	printf("\njcols[%i] = < ",s); 
	for(int k=0;k<s;k++){
		printf("%zu ",jcols[k]);
	}
	printf(">\n");
	printf("\n");

}

template <class fp_type>
void SparseMatrix_COO<fp_type>::matVec(fp_type x[],fp_type b[], size_t N) {
	//obj.csrMatrixVector multiplication
	//returns b vec
	int i=0,j=0;
		for(int k=0;k<_nz;k++){
			//for(int i=0;i<N;i++){
				j = jcols[k];
				i = irows[k];
				b[i] += A[k] * x[j];
			//}
		}

}

template <class fp_type> 
fp_type SparseMatrix_COO<fp_type>::getCoefficient(const size_t row, const size_t col) {
	//returns coefficeint of interest
	//returns zero if not found
	fp_type R = 0;
	auto s = std::make_pair(row,col);
	if (_buildCoeff.find(s) != _buildCoeff.end() ){
		R = _buildCoeff[s];
	}

	return R;
}

template class SparseMatrix_COO<float>;
template class SparseMatrix_COO<double>;

}//endof namespace spmv
