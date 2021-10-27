//TESTS FOR ELLPACK matrix format construction:
//1) Upper Triangular "dense" matrix construction
//2) All zero row
//3) All zero column

#include <vector>                // import vector
#include "ELLPACK.hpp"           // import ELLPACK sparse matrix library
#include "unit_test_framework.h" // for using testing framework

// Test matrix construction for a 3x3 upper triangular matrix
// This tests for a matrix where all rows and columns have values
TEST(Build_ELLPACK_Upper_Triangular)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t maxnz = 3;
    size_t maxnzELLPACK = 0;

    // Initialize the sparse ELLPACK matrix
    SparseMatrix<FP_TYPE> *sparseMatELLPACK = ELLPACK(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // ELLPACK matrix storage vectors
    FP_TYPE denseMat[3][3] = {{1.0, 2.0, 3.0},
                              {0.0, 4.0, 5.0},
                              {0.0, 0.0, 6.0}};

    std::vector<std::vector<FP_TYPE>> elementVec[rows][maxnz] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 0.0}, {6.0, 0.0, 0.0}};
    std::vector<std::vector << int> > columnIdxVec[rows][maxnz] = {{0, 1, 2}, {1, 2, 0}, {2, 0, 0}};

    std::vector<std::vector<FP_TYPE>> elementVecELLPACK[rows][maxnz];
    std::vector<std::vector << int> > columnIdxVecELLPACK[rows][maxnz];

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
    sparseMatELLPACK->setCoefficients(valueMap);

    // Get the ELLPACK sparse storage vectors
    sparseMatELLPACK->getELLPACK(elementVecELLPACK, columnIdxVecELLPACK, maxnzELLPACK);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(maxnz, maxnzELLPACK)
    ASSERT_EQUAL(rows, elementVecELLPACK.size());
    ASSERT_EQUAL(rows, columnIdxVecELLPACK.size());

    for (size_t i = 0, i < rows, i++)
    {
        ASSERT_EQUAL(maxnz, elementVecELLPACK[i].size())
        ASSERT_EQUAL(naxnz, columnIdxVecELLPACK[i].size());
    }

    // Test that the sparse storage arrays are equal
    for (size_t i = 0, i < rows, i++)
    {
        for (size_t j = 0, j < maxnz, j++)
        {
            ASSERT_ALMOST_EQUAL(elementVec[i][j], elementVecELLPACK[i][j], 1e-6);
            ASSERT_ALMOST_EQUAL(columnIdxVec[i][j], columnIdxVecELLPACK[i][j], 1e-6);
        }
    }
}

// Test matrix construction for 3x3 with a zero row
TEST(Build_ELLPACK_Zero_Row)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t maxnz = 3;
    size_t maxnzELLPACK = 0;

    // Initialize the sparse ELLPACK matrix
    SparseMatrix<FP_TYPE> *sparseMatELLPACK = ELLPACK(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // ELLPACK matrix storage vectors
    FP_TYPE denseMat[3][3] = {{1.0, 2.0, 3.0},
                              {0.0, 4.0, 5.0},
                              {0.0, 0.0, 0.0}};

    std::vector<std::vector<FP_TYPE>> elementVec[rows][maxnz] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 0.0}, {0.0, 0.0, 0.0}};
    std::vector<std::vector << int> > columnIdxVec[rows][maxnz] = {{0, 1, 2}, {1, 2, 0}, {0, 0, 0}};

    std::vector<std::vector<FP_TYPE>> elementVecELLPACK[rows][maxnz];
    std::vector<std::vector << int> > columnIdxVecELLPACK[rows][maxnz];

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
    sparseMatELLPACK->setCoefficients(valueMap);

    // Get the ELLPACK sparse storage vectors
    sparseMatELLPACK->getELLPACK(elementVecELLPACK, columnIdxVecELLPACK, maxnzELLPACK);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(maxnz, maxnzELLPACK)
    ASSERT_EQUAL(rows, elementVecELLPACK.size());
    ASSERT_EQUAL(rows, columnIdxVecELLPACK.size());

    for (size_t i = 0, i < rows, i++)
    {
        ASSERT_EQUAL(maxnz, elementVecELLPACK[i].size())
        ASSERT_EQUAL(naxnz, columnIdxVecELLPACK[i].size());
    }

    // Test that the sparse storage arrays are equal
    for (size_t i = 0, i < rows, i++)
    {
        for (size_t j = 0, j < maxnz, j++)
        {
            ASSERT_ALMOST_EQUAL(elementVec[i][j], elementVecELLPACK[i][j], 1e-6);
            ASSERT_ALMOST_EQUAL(columnIdxVec[i][j], columnIdxVecELLPACK[i][j], 1e-6);
        }
    }
}

// Test matrix construction for 3x3 with a zero column
TEST(Build_ELLPACK_Zero_Column)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t maxnz = 2;
    size_t maxnzELLPACK = 0;

    // Initialize the sparse ELLPACK matrix
    SparseMatrix<FP_TYPE> *sparseMatELLPACK = ELLPACK(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // ELLPACK matrix storage vectors
    FP_TYPE denseMat[3][3] = {{1.0, 2.0, 3.0},
                              {0.0, 4.0, 5.0},
                              {0.0, 0.0, 6.0}};

    std::vector<std::vector<FP_TYPE>> elementVec[rows][maxnz] = {{2.0, 3.0}, {4.0, 5.0}, {6.0, 0.0}};
    std::vector<std::vector << int> > columnIdxVec[rows][maxnz] = {{1, 2}, {1, 2}, {2, 0}};

    std::vector<std::vector<FP_TYPE>> elementVecELLPACK[rows][maxnz];
    std::vector<std::vector << int> > columnIdxVecELLPACK[rows][maxnz];

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
    sparseMatELLPACK->setCoefficients(valueMap);

    // Get the ELLPACK sparse storage vectors
    sparseMatELLPACK->getELLPACK(elementVecELLPACK, columnIdxVecELLPACK, maxnzELLPACK);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(maxnz, maxnzELLPACK)
    ASSERT_EQUAL(rows, elementVecELLPACK.size());
    ASSERT_EQUAL(rows, columnIdxVecELLPACK.size());

    for (size_t i = 0, i < rows, i++)
    {
        ASSERT_EQUAL(maxnz, elementVecELLPACK[i].size())
        ASSERT_EQUAL(naxnz, columnIdxVecELLPACK[i].size());
    }

    // Test that the sparse storage arrays are equal
    for (size_t i = 0, i < rows, i++)
    {
        for (size_t j = 0, j < maxnz, j++)
        {
            ASSERT_ALMOST_EQUAL(elementVec[i][j], elementVecELLPACK[i][j], 1e-6);
            ASSERT_ALMOST_EQUAL(columnIdxVec[i][j], columnIdxVecELLPACK[i][j], 1e-6);
        }
    }
}