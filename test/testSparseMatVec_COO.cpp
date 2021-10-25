//TESTS FOR COO format sparse matrix runs 5 tests:
//1) MatVec with identity matrix
//2) MatVec with diagonal matrix
//3) MatVec with zeros Matrix
//4) Matvec with tridiagonal matrix
//5) Matvec with random full desnse matrix

#include "SparseMatrix.hpp" //import sparse matrix library
#include "unit_test_framework.h" //for using testing framework
#include "stdlib.h"//for random

//Test for identity matvec
TEST(MatVec_COO_Identity){
    //num rows and cols for matrix
    size_t rows = 10;
    size_t cols = 10;
    SparseMatrix<FP_TYPE> * mat = Matrix_Factory("COO",rows,cols);
    FP_TYPE x[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    FP_TYPE b[10];
    std::map<std::pair<size_t,size_t>, FP_TYPE > value_Map;
    for(size_t i = 0; i < rows; i++){

        std::pair<size_t,size_t>  key;
        key = std::make_pair(i,i);

        std::pair<std::pair<size_t,size_t>, FP_TYPE> map_pair;
        map_pair = std::make_pair(key,1.0);
        value_Map.insert(map_pair);
    }
    
    //set coefficients of sparse matrix to be the values in the map
    mat->setCoefficients(value_Map);
    mat->matvec(x,b);
    //loop over values of b and check they are the same as x x was multiplied by the identity matrix
    for (size_t i = 0;i < cols; i++){
        ASSERT_ALMOST_EQUAL(x[i],b[i],1e-6);
    }
    delete mat;
}   
//Test For Diagonal matvec 
TEST(MatVec_COO_Diag){
    //num rows and cols for matrix
    size_t rows = 10;
    size_t cols = 10;
    SparseMatrix<FP_TYPE> * mat = Matrix_Factory("COO",rows,cols);
    FP_TYPE x[10] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
    FP_TYPE b[10];
    FP_TYPE b_sol[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    std::map<std::pair<size_t,size_t>, FP_TYPE > value_Map;
    FP_TYPE val  = 1.0;
    for(size_t i = 0; i < rows; i++){
        std::pair<size_t,size_t>  key;
        key = std::make_pair(i,i);

        std::pair<std::pair<size_t,size_t>, FP_TYPE> map_pair;
        map_pair= std::make_pair(key,val);
        value_Map.insert(map_pair);
        val = val + 1; 
    }
    
    //set coefficients of sparse matrix to be the values in the map
    mat->setCoefficients(value_Map);
    mat->matVec(x,b);
    //loop over values of b and check they are the same as b_sol
    for (size_t i = 0;i < cols; i++){
        ASSERT_ALMOST_EQUAL(b_sol[i],b[i],1e-6);
    }
    delete mat;
}   
//Test for zero matrix matvec
TEST(MatVec_COO_Zero){
    //num rows and cols for matrix
    size_t rows = 10;
    size_t cols = 10;
    SparseMatrix<FP_TYPE> * mat = Matrix_Factory("COO",rows,cols);
    FP_TYPE x[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    FP_TYPE b[10];
    mat->matvec(x,b);
    //loop over values of b and check they are the same as x x was multiplied by the identity matrix
    for (size_t i = 0;i < cols; i++){
        ASSERT_ALMOST_EQUAL(0,b[i],1e-6);
    }
    delete mat;
}   
//Tests for banded matvec
TEST(matVec_COO_BANDED){
    //num rows and cols for matrix
    size_t rows = 10;
    size_t cols = 10;
    SparseMatrix<FP_TYPE> * mat = Matrix_Factory("COO",rows,cols);
    FP_TYPE x[10] = {1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
    FP_TYPE b[10];
    FP_TYPE b_sol[10] = {1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0};
    std::map<std::pair<size_t,size_t>, FP_TYPE > value_Map;
    for(size_t i = 0; i < rows; i++){
        std::pair<size_t,size_t>  key;
        key = std::make_pair(i,i);
        std::pair<std::pair<size_t,size_t>, FP_TYPE> map_pair;
        map_pair= std::make_pair(key,2);
        value_Map.insert(map_pair);

        if (i > 0){
            std::pair<size_t,size_t>  key;
            key = std::make_pair(i,i-1);
            std::pair<std::pair<size_t,size_t>, FP_TYPE> map_pair;
            map_pair= std::make_pair(key,-1);
            value_Map.insert(map_pair);
        }
        
        if (i < rows-1){
            std::pair<size_t,size_t>  key;
            key = std::make_pair(i,i+1);
            std::pair<std::pair<size_t,size_t>, FP_TYPE> map_pair;
            map_pair= std::make_pair(key,-1);
            value_Map.insert(map_pair);
        }
    }
    
    //set coefficients of sparse matrix to be the values in the map
    mat->setCoefficients(value_Map);
    mat->matVec(x,b);
    //loop over values of b and check they are the same as b_sol
    for (size_t i = 0;i < cols; i++){
        ASSERT_ALMOST_EQUAL(b_sol[i],b[i],1e-6);
    }
    delete mat;
}
//test for random dense matvec
TEST(MatVec_COO_Dense){
    size_t rows = 10;
    size_t cols = 10;
    SparseMatrix<FP_TYPE> * mat = Matrix_Factory("COO",rows,cols);
    FP_TYPE mat_dense[10][10];
    FP_TYPE x[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
    FP_TYPE b[10];
    FP_TYPE b_sol[10] = {0,0,0,0,0,0,0,0,0,0};
    std::map<std::pair<size_t,size_t>, FP_TYPE > value_Map;
    //set random seed so test dont change run to run
    srand(100);
    for(size_t i = 0; i < rows; i++){
        for (size_t j = 0; j<cols; j++){
            FP_TYPE val = rand();
            mat_dense[i][j] = val;
            std::pair<size_t,size_t>  key;
            key = std::make_pair(i,i);
            std::pair<std::pair<size_t,size_t>, FP_TYPE> map_pair;
            map_pair = std::make_pair(key,val);
            value_Map.insert(map_pair);
        }

    }

    // dense matrix vector multiplication (known implemenation)
    for (size_t i  = 0; i <rows; i++){
        for (size_t j = 0; j<cols; j++){
            b_sol[i] = b_sol[i] + mat_dense[i][j]*x[j];
        }
    }
    
    //set coefficients of sparse matrix to be the values in the map
    mat->setCoefficients(value_Map);
    mat->matvec(x,b);
    //loop over values of b and check they are the same as x x was multiplied by the identity matrix
    for (size_t i = 0;i < cols; i++){
        ASSERT_ALMOST_EQUAL(b_sol[i],b[i],1e-6);
    }

    delete mat;
}

TEST MAIN()