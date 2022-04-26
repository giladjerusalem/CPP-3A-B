#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Matrix.hpp"
#include "doctest.h"

using namespace std;

using namespace zich;


    TEST_CASE("Testing constructor"){
    vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    
    CHECK_THROWS(Matrix A = Matrix(arr,1,1);
    CHECK_THROWS(Matrix A = Matrix(arr,2,1);
    CHECK_THROWS(Matrix A = Matrix(arr,3,1);
    CHECK_THROWS(Matrix A = Matrix(arr,1,3);

    CHECK_NOTTHROWS(Matrix A = Matrix(arr,3,3);
    }


    TEST_CASE("Testing Matrix + Matrix"){

    vector<double> mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double> mat3={1, 0};
    vector<double> mat4={1, 0, 0};

    Matrix A = Matrix(mat1,3,3);
    Matrix B = Matrix(mat2,3,3);
    Matrix C = Matrix(mat3,1,2);
    Matrix D = Matrix(mat4,1,3);
    //Matrix E = Matrix(mat4,1,3);

    CHECK_THROWS(A+C);   
    CHECK_THROWS(A+D);
    CHECK_THROWS(C+D);

    CHECK_NOTTHROWS(A+B);
    //CHECK_NOTTHROWS(D+E);

    }

        TEST_CASE("Testing Matrix ++ "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat3={1, 0};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat3,1,2);

        int i;

        CHECK(A++);   
        CHECK(C++);
        }

        TEST_CASE("Testing Matrix + genery "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix A = Matrix(mat1,3,3);
        
        CHECK(+A);        
        }

///////////////
        TEST_CASE("Testing Matrix + int "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix A = Matrix(mat1,3,3);

        }

/////////////
        TEST_CASE("Testing Matrix - int "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix A = Matrix(mat1,3,3);

        }
        
        TEST_CASE("Testing Matrix - genery "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix A = Matrix(mat1,3,3);
        
        CHECK(-A);
        CHECK_THROWS(A=(-A));    
        }

TEST_CASE("Testing Matrix += "){

    vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double>mat3={1, 0};
    vector<double>mat4={1, 0, 0};

    Matrix A = Matrix(mat1,3,3);
    Matrix B = Matrix(mat2,3,3);
    Matrix C = Matrix(mat3,1,2);
    Matrix D = Matrix(mat4,1,3);
    Matrix E = Matrix(mat4,1,3);

    CHECK_THROWS(A+=C);   
    CHECK_THROWS(A+=D);
    CHECK_THROWS(C+=D);

    CHECK_NOTTHROWS(A+=B);
    CHECK_NOTTHROWS(D+=E);
}

       
    TEST_CASE("Testing Matrix - Matrix"){

    vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double>mat3={1, 0};
    vector<double>mat4={1, 0, 0};

    Matrix A = Matrix(mat1,3,3);
    Matrix B = Matrix(mat2,3,3);
    Matrix C = Matrix(mat3,1,2);
    Matrix D = Matrix(mat4,1,3);
    Matrix E = Matrix(mat4,1,3);

    CHECK_THROWS(A-C);   
    CHECK_THROWS(A-D);
    CHECK_THROWS(C-D);

    CHECK_NOTTHROWS(A-B);
    CHECK_NOTTHROWS(D-E);

    }


        TEST_CASE("Testing Matrix -- Matrix"){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat3={1, 0};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat3,1,2);

        CHECK_THROWS(A--);   
        CHECK_THROWS(C--);
        }


        TEST_CASE("Testing Matrix -= "){    //mat-=mat
    vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double>mat3={1, 0};
    vector<double>mat4={1, 0, 0};

    Matrix A = Matrix(mat1,3,3);
    Matrix B = Matrix(mat2,3,3);
    Matrix C = Matrix(mat3,1,2);
    Matrix D = Matrix(mat4,1,3);
    Matrix E = Matrix(mat4,1,3);

    CHECK_THROWS(A-=C);   
    CHECK_THROWS(A-=D);
    CHECK_THROWS(C-=D);

    CHECK_NOTTHROWS(A-=B);
    CHECK_NOTTHROWS(D-=E);
}
        


        TEST_CASE("Testing Matrix * Matrix"){   //mat*mat

        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        vector<double>mat3={1, 0};
        vector<double>mat4={1, 0};

        Matrix A = Matrix(mat1,3,3);
        Matrix B = Matrix(mat2,3,3);
        Matrix C = Matrix(mat3,1,2);
        Matrix D = Matrix(mat4,1,2);

        CHECK_THROWS(A*C);   
        CHECK_THROWS(A*D);
        CHECK_THROWS(C*D);

        CHECK_NOTTHROWS(A*B);
        CHECK_NOTTHROWS(C*D);
        }

        TEST_CASE("Testing Matrix *= Matrix"){  //mat*=mat
        
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        vector<double>mat3={0, 3, 0, 0, 0, 3};
        vector<double>mat4={1, 0};

        Matrix A = Matrix(mat1,3,3);
        Matrix B = Matrix(mat2,3,3);
        Matrix C = Matrix(mat3,2,3);
        Matrix D = Matrix(mat4,1,2);

        CHECK_THROWS(A*=C);   
        CHECK_THROWS(A*=D);
        CHECK_THROWS(C*=D);

        CHECK_NOTTHROWS(A*=B);
        CHECK_NOTTHROWS(D*=C);
        }

        TEST_CASE("Testing Matrix *= num"){    //mat*num
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        vector<double>mat3={0, 3, 0, 0, 0, 3};
        
        double num =3.1;

        Matrix A = Matrix(mat1,3,3);
        Matrix B = Matrix(mat2,3,3);
        Matrix C = Matrix(mat3,2,3);

        CHECK_THROWS(A*num);   
        CHECK_THROWS(C*num);

        CHECK_NOTTHROWS(A*num);
        CHECK_NOTTHROWS(C*num);
        }


        TEST_CASE("Testing Matrix == Matrix"){
        vector<double>mat0={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        vector<double>mat3={1, 0};
        vector<double>mat4={1, 0};

        Matrix A = Matrix(mat1,3,3);
        Matrix B = Matrix(mat2,3,3);
        Matrix C = Matrix(mat3,1,2);
        Matrix D = Matrix(mat4,1,2);
        Matrix E = Matrix(mat0,3,3);
        
        CHECK_THROWS(A==C);   
        CHECK_THROWS(A==B);
        CHECK_THROWS(C==E);

        CHECK_NOTTHROWS(A==E);
        CHECK_NOTTHROWS(C==D);
        }


        TEST_CASE("Testing Matrix != Matrix"){
        
        vector<double>mat0={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        vector<double>mat3={1, 0};
        vector<double>mat4={1, 0};
        vector<double>mat5={1, 1};

        Matrix A = Matrix(mat1,3,3);
        Matrix B = Matrix(mat2,3,3);
        Matrix C = Matrix(mat3,1,2);
        Matrix D = Matrix(mat4,1,2);
        Matrix E = Matrix(mat5,1,2);
        
        CHECK_THROWS(A!=E);   
        CHECK_THROWS(C!=D);

        CHECK_NOTTHROWS(A!=B);
        CHECK_NOTTHROWS(A!=C);
        CHECK_NOTTHROWS(C!=E);
        }

    TEST_CASE("Testing Matrix < Matrix"){
        
        vector<double>mat0={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        
        Matrix A = Matrix(mat0,3,3);
        Matrix B = Matrix(mat1,3,3);
        Matrix C = Matrix(mat2,1,2);

        CHECK_THROWS(A<C);   

        CHECK_NOTTHROWS(A<B);
        CHECK_NOTTHROWS(C<A);

        // int i=0;
        // int j =0;

        // for(i=0; i<3; i++){
        //     for(j=0; j<3; j++){
        //         CHECK_TROWS(A[i][j]<B[i][j]) 
        //     }
        // }
        // for(i=0; i<3; i++){
        //     for(j=0; j<3; j++){
        //         CHECK(A[i][j]<C[i][j]) 
        //     }
        // }
    
    }

        TEST_CASE("Testing Matrix <= Matrix"){
        
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat2,1,2);

        CHECK_THROWS(C<=A);   
        CHECK_NOTTHROWS(A<=C);
        // int i=0;
        // int j =0;

        // for(i=0; i<3; i++){
        //     for(j=0; j<3; j++){
        //         CHECK_TROWS(C[i][j]<=A[i][j]) 
        //     }
        // }
        // for(i=0; i<3; i++){
        //     for(j=0; j<3; j++){
        //         CHECK(A[i][j]<=C[i][j]) 
        //     }
        // }

    }

        TEST_CASE("Testing Matrix > Matrix"){
        
        vector<double>mat0={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        
        Matrix A = Matrix(mat0,3,3);
        Matrix B = Matrix(mat1,3,3);
        Matrix C = Matrix(mat2,1,2);


        CHECK_THROWS(A>C);   
        CHECK_THROWS(A>B);
        CHECK_NOTTHROWS(C>A);
        // int i=0;
        // int j =0;

        // for(i=0; i<3; i++){
        //     for(j=0; j<3; j++){
        //         CHECK_TROWS(A[i][j]>B[i][j]) 
        //     }
        // }
        // for(i=0; i<3; i++){
        //     for(j=0; j<3; j++){
        //         CHECK(C[i][j]>A[i][j]) 
        //     }
        // } 

        }


        TEST_CASE("Testing Matrix >= Matrix"){

        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat2,1,2);

        CHECK_THROWS(A>=C);   
        CHECK_NOTTHROWS(C>=A);

        // int i=0;
        // int j =0;

        // for(i=0; i<3; i++){
        //     for(j=0; j<3; j++){
        //         CHECK_TROWS(A[i][j]>=C[i][j]) 
        //     }
        // }
        // for(i=0; i<3; i++){
        //     for(j=0; j<3; j++){
        //         CHECK(C[i][j]>=A[i][j]) 
        //     }
        // } 

        }
        TEST_CASE("input & output"){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat3={1, 0};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat3,1,2);
        
        //how to check?

        }




        




