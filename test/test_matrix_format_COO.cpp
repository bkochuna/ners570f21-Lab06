//TESTS FOR COO matrix format construction:
//1) Upper Triangular "dense" matrix construction
//2) All zero row
//3) All zero column

#include <vector>                // import vector
#include "COO.hpp"               // import COO sparse matrix library
#include "unit_test_framework.h" // for using testing framework

// Test matrix construction for a 3x3 upper triangular matrix
// This tests for a matrix where all rows and columns have values
TEST(Build_COO_Upper_Triangular)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t nnz = 6;

    // Initialize the sparse COO matrix
    SparseMatrix<FP_TYPE> *sparseMatCOO = COO(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // COO matrix storage vectors
    FP_TYPE denseMat[3][3] = {{1.0, 2.0, 3.0},
                              {0.0, 4.0, 5.0},
                              {0.0, 0.0, 6.0}};

    std::vector<FP_TYPE> elementVec[nnz] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<int> columnIdxVec[nnz] = {0, 1, 2, 1, 2, 2};
    std::vector<int> rowIdxVec[nnz] = {0, 0, 0, 1, 1, 2};

    std::vector<FP_TYPE> elementVecCOO[nnz];
    std::vector<FP_TYPE> columnIdxVecCOO[nnz];
    std::vector<FP_TYPE> rowIdxVecCOO[nnz];

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
    sparseMatCOO->setCoefficients(valueMap);

    // Get the COO sparse storage vectors
    sparseMatCOO->getCOO(elementVecCOO, columnIdxVecCOO, rowIdxVecCOO);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(nnz, elementVecCOO.size());
    ASSERT_EQUAL(nnz, columnIdxVecCOO.size());
    ASSERT_EQUAL(nnz, rowIdxVecCOO.size());

    // Test that the sparse storage arrays are equal
    for (size_t i = 0, i < nnz, i++)
    {
        ASSERT_ALMOST_EQUAL(elementVec[i], elementVecCOO[i], 1e-6);
    }
    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecCOO);
    ASSERT_SEQUENCE_EQUAL(rowIdxVec, rowIdxVecCOO);
}

// Test matrix construction for 3x3 with a zero row
TEST(Build_COO_Zero_Row)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t nnz = 4;

    // Initialize the sparse COO matrix
    SparseMatrix<FP_TYPE> *sparseMatCOO = COO(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // COO matrix storage vectors
    FP_TYPE denseMat[3][3] = {{1.0, 2.0, 3.0},
                              {0.0, 0.0, 0.0},
                              {0.0, 0.0, 6.0}};

    std::vector<FP_TYPE> elementVec[nnz] = {1.0, 2.0, 3.0, 6.0};
    std::vector<int> columnIdxVec[nnz] = {0, 1, 2, 2};
    std::vector<int> rowIdxVec[nnz] = {0, 0, 0, 2};

    std::vector<FP_TYPE> elementVecCOO[nnz];
    std::vector<FP_TYPE> columnIdxVecCOO[nnz];
    std::vector<FP_TYPE> rowIdxVecCOO[nnz];

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
    sparseMatCOO->setCoefficients(valueMap);

    // Get the COO sparse storage vectors
    sparseMatCOO->getCOO(elementVecCOO, columnIdxVecCOO, rowIdxVecCOO);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(nnz, elementVecCOO.size());
    ASSERT_EQUAL(nnz, columnIdxVecCOO.size());
    ASSERT_EQUAL(nnz, rowIdxVecCOO.size());

    // Test that the sparse storage arrays are equal
    for (size_t i = 0, i < nnz, i++)
    {
        ASSERT_ALMOST_EQUAL(elementVec[i], elementVecCOO[i], 1e-6);
    }
    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecCOO);
    ASSERT_SEQUENCE_EQUAL(rowIdxVec, rowIdxVecCOO);
}

// Test matrix construction for 3x3 with a zero column
TEST(Build_COO_Zero_Column)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t nnz = 5;

    // Initialize the sparse COO matrix
    SparseMatrix<FP_TYPE> *sparseMatCOO = COO(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // COO matrix storage vectors
    FP_TYPE denseMat[3][3] = {{0.0, 2.0, 3.0},
                              {0.0, 4.0, 5.0},
                              {0.0, 0.0, 6.0}};

    std::vector<FP_TYPE> elementVec[nnz] = {2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<int> columnIdxVec[nnz] = {1, 2, 1, 2, 2};
    std::vector<int> rowIdxVec[nnz] = {0, 0, 1, 1, 2};

    std::vector<FP_TYPE> elementVecCOO[nnz];
    std::vector<FP_TYPE> columnIdxVecCOO[nnz];
    std::vector<FP_TYPE> rowIdxVecCOO[nnz];

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
    sparseMatCOO->setCoefficients(valueMap);

    // Get the COO sparse storage vectors
    sparseMatCOO->getCOO(elementVecCOO, columnIdxVecCOO, rowIdxVecCOO);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(nnz, elementVecCOO.size());
    ASSERT_EQUAL(nnz, columnIdxVecCOO.size());
    ASSERT_EQUAL(nnz, rowIdxVecCOO.size());

    // Test that the sparse storage arrays are equal
    for (size_t i = 0, i < nnz, i++)
    {
        ASSERT_ALMOST_EQUAL(elementVec[i], elementVecCOO[i], 1e-6);
    }
    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecCOO);
    ASSERT_SEQUENCE_EQUAL(rowIdxVec, rowIdxVecCOO);
}