//TESTS FOR JDS matrix format construction:
//1) Upper Triangular "dense" matrix construction
//2) All zero row
//3) All zero column

#include <vector>                // import vector
#include "JDS.hpp"               // import JDS sparse matrix library
#include "unit_test_framework.h" // for using testing framework

// Test matrix construction for a 3x3 upper triangular matrix
// This tests for a matrix where all rows and columns have values
TEST(Build_JDS_Upper_Triangular)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t nnz = 6;

    // Initialize the sparse JDS matrix
    SparseMatrix<FP_TYPE> *sparseMatJDS = JDS(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // JDS matrix storage vectors
    FP_TYPE denseMat[3][3] = {{1.0, 2.0, 3.0},
                              {0.0, 4.0, 5.0},
                              {0.0, 0.0, 6.0}};

    std::vector<FP_TYPE> jDiagVec[nnz] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<int> columnIdxVec[nnz] = {0, 1, 2, 1, 2, 2};
    std::vector<int> permVec[rows] = {0, 1, 2};
    std::vector<int> jdPtrVec[3] = [ 0, 3, 5 ];

    std::vector<FP_TYPE> jDiagVecJDS[nnz];
    std::vector<int> columnIdxVecJDS[nnz];
    std::vector<int> permVecJDS[rows];
    std::vector<int> jdPtrVecJDS[3];

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
    sparseMatJDS->setCoefficients(valueMap);

    // Get the JDS sparse storage vectors
    sparseMatJDS->getJDS(permVecJDS, jDiagVecJDS, columnIdxVecJDS, jdPtrVecJDS);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(nnz, elementVecJDS.size());
    ASSERT_EQUAL(nnz, columnIdxVecJDS.size());
    ASSERT_EQUAL(rows, permVecJDS.size());
    ASSERT_EQUAL(3, jdPtrVecJDS.size());

    // Test that the sparse storage arrays are equal
    for (int i = 0, i < nnz, i++)
    {
        ASSERT_ALMOST_EQUAL(elementVec[i], elementVecJDS[i], 1e-6);
    }

    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecJDS)
    ASSERT_SEQUENCE_EQUAL(permVec, permVecJDS)
    ASSERT_SEQUENCE_EQUAL(jdPtrVec, jdPtrVecJDS)
}

// Test matrix construction for 3x3 with a zero row
TEST(Build_JDS_Zero_Row)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t nnz = 5;

    // Initialize the sparse JDS matrix
    SparseMatrix<FP_TYPE> *sparseMatJDS = JDS(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // JDS matrix storage vectors
    FP_TYPE denseMat[3][3] = {{1.0, 2.0, 3.0},
                              {0.0, 4.0, 5.0},
                              {0.0, 0.0, 0.0}};

    std::vector<FP_TYPE> jDiagVec[nnz] = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<int> columnIdxVec[nnz] = {0, 1, 2, 1, 2};
    std::vector<int> permVec[rows] = {0, 1, 2};
    std::vector<int> jdPtrVec[3] = [ 0, 3, 4 ];

    std::vector<FP_TYPE> jDiagVecJDS[nnz];
    std::vector<int> columnIdxVecJDS[nnz];
    std::vector<int> permVecJDS[rows];
    std::vector<int> jdPtrVecJDS[3];

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
    sparseMatJDS->setCoefficients(valueMap);

    // Get the JDS sparse storage vectors
    sparseMatJDS->getJDS(permVecJDS, jDiagVecJDS, columnIdxVecJDS, jdPtrVecJDS);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(nnz, elementVecJDS.size());
    ASSERT_EQUAL(nnz, columnIdxVecJDS.size());
    ASSERT_EQUAL(rows, permVecJDS.size());
    ASSERT_EQUAL(3, jdPtrVecJDS.size());

    // Test that the sparse storage arrays are equal
    for (int i = 0, i < nnz, i++)
    {
        ASSERT_ALMOST_EQUAL(elementVec[i], elementVecJDS[i], 1e-6);
    }

    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecJDS)
    ASSERT_SEQUENCE_EQUAL(permVec, permVecJDS)
    ASSERT_SEQUENCE_EQUAL(jdPtrVec, jdPtrVecJDS)
}

// Test matrix construction for 3x3 with a zero column
TEST(Build_JDS_Zero_Column)
{
    size_t rows = 3;
    size_t cols = 3;
    size_t nnz = 5;

    // Initialize the sparse JDS matrix
    SparseMatrix<FP_TYPE> *sparseMatJDS = JDS(rows, cols);

    // Initializse the pre-determined dense matrix and the assumed
    // JDS matrix storage vectors
    FP_TYPE denseMat[3][3] = {{0.0, 2.0, 3.0},
                              {0.0, 4.0, 5.0},
                              {0.0, 0.0, 6.0}};

    std::vector<FP_TYPE> jDiagVec[nnz] = {2.0, 3.0, 4.0, 5.0, 6.0};
    std::vector<int> columnIdxVec[nnz] = {1, 2, 1, 2, 2};
    std::vector<int> permVec[rows] = {0, 1, 2};
    std::vector<int> jdPtrVec[3] = [ 0, 3, 4 ];

    std::vector<FP_TYPE> jDiagVecJDS[nnz];
    std::vector<int> columnIdxVecJDS[nnz];
    std::vector<int> permVecJDS[rows];
    std::vector<int> jdPtrVecJDS[3];

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
    sparseMatJDS->setCoefficients(valueMap);

    // Get the JDS sparse storage vectors
    sparseMatJDS->getJDS(permVecJDS, jDiagVecJDS, columnIdxVecJDS, jdPtrVecJDS);

    // Test that the size of the sparse storage arrays are correct
    ASSERT_EQUAL(nnz, elementVecJDS.size());
    ASSERT_EQUAL(nnz, columnIdxVecJDS.size());
    ASSERT_EQUAL(rows, permVecJDS.size());
    ASSERT_EQUAL(3, jdPtrVecJDS.size());

    // Test that the sparse storage arrays are equal
    for (int i = 0, i < nnz, i++)
    {
        ASSERT_ALMOST_EQUAL(elementVec[i], elementVecJDS[i], 1e-6);
    }

    ASSERT_SEQUENCE_EQUAL(columnIdxVec, columnIdxVecJDS)
    ASSERT_SEQUENCE_EQUAL(permVec, permVecJDS)
    ASSERT_SEQUENCE_EQUAL(jdPtrVec, jdPtrVecJDS)
}