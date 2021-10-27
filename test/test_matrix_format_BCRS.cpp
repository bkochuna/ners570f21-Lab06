//TESTS FOR BCRS matrix format construction:
//1) Upper Triangular "dense" matrix construction
//2) All zero row
//3) All zero column

#include <vector>                // import vector
#include "BCRS.hpp"              // import BCRS sparse matrix library
#include "unit_test_framework.h" // for using testing framework

// Test matrix construction for a 3x3 upper triangular matrix
// This tests for a matrix where all rows and columns have values
TEST(Build_BCRS_Upper_Triangular)
{
    size_t rows = 8;
    size_t cols = 8;

    size_t nnzb = 9; // Number of non-zero blocks
    size_t nb = 2;   // Block dimensions
    size_t nd = 4;   // Number of block rows

    // Initialize the sparse BCRS matrix
    SparseMatrix<FP_TYPE> *sparseMatBCRS = BCRS(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // BCRS matrix storage vectors
    FP_TYPE denseMat[rows][cols] = {{6.0, 0.0, 9.0, 0.0, 0.0, 4.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 0.0, 0.0},
                                    {0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 3.0, 5.0, 8.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 6.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 3.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0}};

    std::vector<std::vector<std::vector<fp_type>>> elementVec[nnzb][nb][nb] = {{{6.0, 0.0}, {0.0, 0.0}},
                                                                               {{9.0, 0.0}, {0.0, 0.0}},
                                                                               {{0.0, 4.0}, {0.0, 4.0}},
                                                                               {{0.0, 5.0}, {0.0, 0.0}},
                                                                               {{0.0, 0.0}, {3.0, 5.0}},
                                                                               {{0.0, 0.0}, {8.0, 0.0}},
                                                                               {{6.0, 0.0}, {0.0, 5.0}},
                                                                               {{0.0, 0.0}, {4.0, 0.0}},
                                                                               {{3.0, 0.0}, {2.0, 2.0}}};
    std::vector<int> columnIdxVec[nnz] = {0, 1, 2, 0, 1, 2, 2, 2, 3};
    std::vector<int> rowIdxVec[nnz] = {0, 3, 6, 7, 9};

    std::vector<std::vector<std::vector<fp_type>>> elementVecBCRS[nnzb][nb][nb];
    std::vector<FP_TYPE> columnIdxVecBCRS[nnz];
    std::vector<FP_TYPE> rowIdxVecBCRS[nnz];

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
    sparseMatBCRS->setCoefficients(valueMap);

    // Get the BCRS sparse storage vectors
    sparseMatBCRS->getBCRS(elementVecBCRS, columnIdxVecBCRS, rowIdxVecBCRS, nb);

    // Test that the size of the sparse storage arrays are correct
    // Need to check each dimension of the block element tensor
    ASSERT_EQUAL(nnzb, elementVecBCRS.size());

    for (int i = 0, i < nnzb, i++)
    {
        ASSERT_EQUAL(nb, elementVecBCRS[i].size())
    }

    for (int i = 0, i < nnzb, i++)
    {
        for (int j = 0, j < nb, j++)
        {
            ASSERT_EQUAL(nb, elementVecBCRS[i][j].size())
        }
    }

    ASSERT_EQUAL(nnzb, columnIdxVecBCRS.size());
    ASSERT_EQUAL(nd + 1, rowIdxVecBCRS.size());

    for (int i = 0, i < nnzb, i++)
    {
        for (int j = 0, j < nb, j++)
        {
            for (int k = k, k < nb, k++)
            {
                ASSERT_ALMOST_EQUAL(elementVec[i][j][k], elementVecBCRS[i][j][k], 1e-6)
            }
        }
    }

    // Test that the sparse storage arrays are equal
    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecBCRS);
    ASSERT_SEQUENCE_EQUAL(rowIdxVec, rowIdxVecBCRS);
}

// Test matrix construction for 3x3 with a zero row
TEST(Build_BCRS_Zero_Row)
{
    size_t rows = 8;
    size_t cols = 8;

    size_t nnzb = 6; // Number of non-zero blocks
    size_t nb = 2;   // Block dimensions
    size_t nd = 4;   // Number of block rows

    // Initialize the sparse BCRS matrix
    SparseMatrix<FP_TYPE> *sparseMatBCRS = BCRS(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // BCRS matrix storage vectors
    FP_TYPE denseMat[rows][cols] = {{0.0, 0.0, 9.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 3.0, 5.0, 8.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 6.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 3.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0}};

    std::vector<std::vector<std::vector<fp_type>>> elementVec[nnzb][nb][nb] = {{{0.0, 5.0}, {0.0, 0.0}},
                                                                               {{0.0, 0.0}, {3.0, 5.0}},
                                                                               {{0.0, 0.0}, {8.0, 0.0}},
                                                                               {{6.0, 0.0}, {0.0, 5.0}},
                                                                               {{0.0, 0.0}, {4.0, 0.0}},
                                                                               {{3.0, 0.0}, {2.0, 2.0}}};
    std::vector<int> columnIdxVec[nnz] = {0, 1, 2, 2, 2, 3};
    std::vector<int> rowIdxVec[nnz] = {0, 0, 3, 4, 6};

    std::vector<std::vector<std::vector<fp_type>>> elementVecBCRS[nnzb][nb][nb];
    std::vector<FP_TYPE> columnIdxVecBCRS[nnz];
    std::vector<FP_TYPE> rowIdxVecBCRS[nnz];

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
    sparseMatBCRS->setCoefficients(valueMap);

    // Get the BCRS sparse storage vectors
    sparseMatBCRS->getBCRS(elementVecBCRS, columnIdxVecBCRS, rowIdxVecBCRS, nb);

    // Test that the size of the sparse storage arrays are correct
    // Need to check each dimension of the block element tensor
    ASSERT_EQUAL(nnzb, elementVecBCRS.size());

    for (int i = 0, i < nnzb, i++)
    {
        ASSERT_EQUAL(nb, elementVecBCRS[i].size())
    }

    for (int i = 0, i < nnzb, i++)
    {
        for (int j = 0, j < nb, j++)
        {
            ASSERT_EQUAL(nb, elementVecBCRS[i][j].size())
        }
    }

    ASSERT_EQUAL(nnzb, columnIdxVecBCRS.size());
    ASSERT_EQUAL(nd + 1, rowIdxVecBCRS.size());

    for (int i = 0, i < nnzb, i++)
    {
        for (int j = 0, j < nb, j++)
        {
            for (int k = k, k < nb, k++)
            {
                ASSERT_ALMOST_EQUAL(elementVec[i][j][k], elementVecBCRS[i][j][k], 1e-6)
            }
        }
    }

    // Test that the sparse storage arrays are equal
    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecBCRS);
    ASSERT_SEQUENCE_EQUAL(rowIdxVec, rowIdxVecBCRS);
}

// Test matrix construction for 3x3 with a zero column
TEST(Build_BCRS_Zero_Column)
{
    size_t rows = 8;
    size_t cols = 8;

    size_t nnzb = 7; // Number of non-zero blocks
    size_t nb = 2;   // Block dimensions
    size_t nd = 4;   // Number of block rows

    // Initialize the sparse BCRS matrix
    SparseMatrix<FP_TYPE> *sparseMatBCRS = BCRS(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // BCRS matrix storage vectors
    FP_TYPE denseMat[rows][cols] = {{0.0, 0.0, 9.0, 0.0, 0.0, 4.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 3.0, 5.0, 8.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 6.0, 0.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 0.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 3.0, 0.0},
                                    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 2.0}};

    std::vector<std::vector<std::vector<fp_type>>> elementVec[nnzb][nb][nb] = {{{9.0, 0.0}, {0.0, 0.0}},
                                                                               {{0.0, 4.0}, {0.0, 4.0}},
                                                                               {{0.0, 0.0}, {3.0, 5.0}},
                                                                               {{0.0, 0.0}, {8.0, 0.0}},
                                                                               {{6.0, 0.0}, {0.0, 5.0}},
                                                                               {{0.0, 0.0}, {4.0, 0.0}},
                                                                               {{3.0, 0.0}, {2.0, 2.0}}};
    std::vector<int> columnIdxVec[nnz] = {1, 2, 1, 2, 2, 2, 3};
    std::vector<int> rowIdxVec[nnz] = {0, 2, 4, 5, 7};

    std::vector<std::vector<std::vector<fp_type>>> elementVecBCRS[nnzb][nb][nb];
    std::vector<FP_TYPE> columnIdxVecBCRS[nnz];
    std::vector<FP_TYPE> rowIdxVecBCRS[nnz];

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
    sparseMatBCRS->setCoefficients(valueMap);

    // Get the BCRS sparse storage vectors
    sparseMatBCRS->getBCRS(elementVecBCRS, columnIdxVecBCRS, rowIdxVecBCRS, nb);

    // Test that the size of the sparse storage arrays are correct
    // Need to check each dimension of the block element tensor
    ASSERT_EQUAL(nnzb, elementVecBCRS.size());

    for (int i = 0, i < nnzb, i++)
    {
        ASSERT_EQUAL(nb, elementVecBCRS[i].size())
    }

    for (int i = 0, i < nnzb, i++)
    {
        for (int j = 0, j < nb, j++)
        {
            ASSERT_EQUAL(nb, elementVecBCRS[i][j].size())
        }
    }

    ASSERT_EQUAL(nnzb, columnIdxVecBCRS.size());
    ASSERT_EQUAL(nd + 1, rowIdxVecBCRS.size());

    for (int i = 0, i < nnzb, i++)
    {
        for (int j = 0, j < nb, j++)
        {
            for (int k = k, k < nb, k++)
            {
                ASSERT_ALMOST_EQUAL(elementVec[i][j][k], elementVecBCRS[i][j][k], 1e-6)
            }
        }
    }

    // Test that the sparse storage arrays are equal
    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecBCRS);
    ASSERT_SEQUENCE_EQUAL(rowIdxVec, rowIdxVecBCRS);
}