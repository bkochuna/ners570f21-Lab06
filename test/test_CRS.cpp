#include "CRS.hpp"
#include <iostream>
#include <petscksp.h>
#include "petscmat.h" 
using namespace spmv;

// Test matrix vector multiplication with specified vector for CRS format
TEST(matVec_CRS)
{
    size_t rows = 5;
    size_t cols = 5;
    size_t nnz = 11;

    // Initialize the sparse CRS matrix
    SparseMatrix<FP_TYPE> *sparseMatCRS = CRS(rows, cols);

    // Initialize the pre-determined dense matrix and the assumed
    // CRS matrix storage vectors
    FP_TYPE denseMat[5][5] = {{0.0, 2.0, 3.0, 0.0, 0.04},
                              {0.0, 4.0, 5.0, 9.65, 0.0},
                              {0.0, 0.0, 6.0, 0.0, 0.0}, 
                              {0.0, 45.0, 0.0, 5.64, 0.0}, 
                              {23.534, 0.0, 0.0, 0.0, 0.90}};

    std::vector<FP_TYPE> elementVec[nnz] = {2.0, 3.0, 0.04, 4.0, 5.0, 9.65, 6.0, 45.0, 5.64, 23.534, 0.90};
    std::vector<int> columnIdxVec[nnz] = {1, 2, 4, 1, 2, 3, 2, 1, 3, 0, 4};
    std::vector<int> rowPtrVec[nnz] = {0, 0, 0, 1, 1, 1, 2, 3, 3, 4, 4};

    std::vector<FP_TYPE> elementVecCRS[nnz];
    std::vector<FP_TYPE> columnIdxVecCRS[nnz];
    std::vector<FP_TYPE> rowPtrVecCRS[nnz];

    std::map<std::pair<size_t, size_t>, FP_TYPE> *valueMap;

    // Assemble to value map
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            // Create the map key with the i, j index of the value
            std::pair<size_t, size_t> key;
            key = std::make_pair(i, j);

            // Create the map and add the value from the dense matrix
            std::pair<size_t, size_t>, FP_TYPE > mapPair;
            mapPair = std::make_pair(key, denseMat[i][j]);
            valueMap->insert(mapPair);
        }
    }

    // Set the matrix coefficients
    sparseMatCRS->setCoefficients(valueMap);

    // Get the CRS sparse storage vectors
    sparseMatCRS->getCRS(elementVecCRS, columnIdxVecCRS, rowPtrVecCRS);

    // Create test vector
    std::vector<FP_TYPE> randVec[nrows] = {0., 40.35, 0.25, 9.04, 24.76};

    //Result vector 
    std::vector<FP_TYPE> resultVec[nrows]; 
    resultVec = matVec(sparseMatCRS, randVec);

    // Perform the same operation using PETSC
    Vec randVecP, resultVecP;
    Mat A;
    PetscInt m, n;
    PetscScalar rand, res, v;
    m = nrows; 
    n = ncols;
    PetscInt rowsIdxVec, colsIdxVec;

    ierr = MatCreate(PETSC_COMM_WORLD,&A);CHKERRQ(ierr);
    ierr = MatSetSizes(A,PETSC_DECIDE,PETSC_DECIDE,m*n,m*n);CHKERRQ(ierr);
    ierr = MatSetFromOptions(A);CHKERRQ(ierr);
    ierr = MatSetUp(A);CHKERRQ(ierr);

    //Copy the values of the dense matrix into the array of values for the PETSC matrix
    for(int i=0; i<ncols*nrows; i++){
        v[i] = denseMat[i];
    }
    //Copy indices of non zero values to Petsc pointers
    for(int i=0;i<nnz;i++){
        rowsIdxVec[i] = rowPtrVec;
        colsIdxVec[i] = colsIdxVec;
    }
    ierr = MatSetValues(A, m,rowsIdxVec, n,colsIdxVec,v,INSERT_VALUES);

    //Copy values of random vector into PETSC vector
    for(int i=0;i<nrows;i++){
        rand[i] = randVec[i];
    }
    //Create and instantiate vector PETSC
    VecCreateSeqWithArray(PETSC_COMM_SELF,1,nrows,rand,&randVecP);
    VecAssemblyBegin(randVecP);
    VecAssemblyEnd(randVecP);

    //Create vector results PETSC
    VecCreateSeqWithArray(PETSC_COMM_SELF,1,nrows,rand,&resultVecP);
    VecAssemblyBegin(resultVecP);
    VecAssemblyEnd(resultVecP);

    //Compute the matrix vector multiplication with PETSC
    MatMult(A,randVecP,resultVecP);
    // Test that the sparse storage arrays are equal
    for (size_t i = 0, i < nnz, i++)
    {
        ASSERT_ALMOST_EQUAL(resultVec[i], resultVecP[i], 1e-6);
    }
}
