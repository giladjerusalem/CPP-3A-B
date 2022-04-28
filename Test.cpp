// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>
// #include <vector>

#include "Matrix.hpp"
#include "doctest.h"

using namespace std;

using namespace zich;
    vector<double> mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double> mat3={1, 0};
    vector<double> mat4={1, 0, 0};

    Matrix A = Matrix(mat1,3,3);
    Matrix B = Matrix(mat2,3,3);
    Matrix C = Matrix(mat3,1,2);
    Matrix D = Matrix(mat4,1,3);

    TEST_CASE("Testing constructor"){
    vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    
    CHECK_THROWS(Matrix A = Matrix(arr,1,1));
    CHECK_THROWS(Matrix A = Matrix(arr,2,1));
    CHECK_THROWS(Matrix A = Matrix(arr,3,1));
    CHECK_THROWS(Matrix A = Matrix(arr,1,3));

    CHECK_NOTHROW(Matrix A = Matrix(arr,3,3));
    }


    TEST_CASE("Testing Matrix + Matrix"){


    //Matrix E = Matrix(mat4,1,3);

    CHECK_THROWS(A+C);   
    CHECK_THROWS(A+D);
    CHECK_THROWS(C+D);

    CHECK_NOTHROW(A+B);
    //CHECK_NOTHROW(D+E);

    }

        TEST_CASE("Testing Matrix ++ "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat3={1, 0};
        vector<double>mat11={2, 1, 1, 1, 2, 1, 1, 1, 2};
        vector<double>mat33={2, 1};

        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat3,1,2);
        Matrix Aa = Matrix(mat1,3,3);
        Matrix Cc = Matrix(mat3,1,2);


        CHECK_NOTHROW(A++);   
        CHECK_NOTHROW(C++);

        }

        TEST_CASE("Testing Matrix + genery "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix A = Matrix(mat1,3,3);
        
        CHECK_NOTHROW(+A);        
        }

///////////////
        TEST_CASE("Testing Matrix + int "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix A = Matrix(mat1,3,3);
        int i =2;
        int j =23;
        CHECK_NOTHROW(A+i);        
        CHECK_NOTHROW(A+j);        

        }

/////////////
        TEST_CASE("Testing Matrix - int "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix A = Matrix(mat1,3,3);
        int i =2;
        int j =3;
        CHECK_NOTHROW(A-i);  
        CHECK_NOTHROW(A-j);            
        }
        
        TEST_CASE("Testing Matrix - genery "){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        Matrix A = Matrix(mat1,3,3);
        vector<double>mat2={2, 1, 0, 0, 1, 0, 0, 0, 1};
        Matrix B = Matrix(mat2,3,3);
        CHECK_NOTHROW(-A);
        CHECK_NOTHROW(-B);
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

    CHECK_NOTHROW(A+=B);
    CHECK_NOTHROW(D+=E);
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

    CHECK_NOTHROW(A-B);
    CHECK_NOTHROW(D-E);

    }


        TEST_CASE("Testing Matrix -- Matrix"){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat3={1, 0};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat3,1,2);

        CHECK_NOTHROW(A--);   
        CHECK_NOTHROW(C--);
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

    CHECK_NOTHROW(A-=B);
    CHECK_NOTHROW(D-=E);
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
        CHECK_NOTHROW(A*B);
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

        CHECK_NOTHROW(A*=B);
        CHECK_NOTHROW(D*=C);
        }

        TEST_CASE("Testing Matrix *= num"){    //mat*num
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        vector<double>mat3={0, 3, 0, 0, 0, 3};
        
        double num =3.1;

        Matrix A = Matrix(mat1,3,3);
        Matrix B = Matrix(mat2,3,3);
        Matrix C = Matrix(mat3,2,3);
        CHECK_NOTHROW(A*num);
        CHECK_NOTHROW(B*num);
        CHECK_NOTHROW(C*num);
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
        
        CHECK_FALSE(A==B);
        CHECK(A==E);
        CHECK(C==D);
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
        
        CHECK_FALSE(A!=A);
        CHECK_FALSE(C!=D);
        CHECK(C!=E);
        }

    TEST_CASE("Testing Matrix < Matrix"){
        
        vector<double>mat0={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        
        Matrix A = Matrix(mat0,3,3);
        Matrix B = Matrix(mat1,3,3);
        Matrix C = Matrix(mat2,3,3);

        CHECK(A<C);   
        CHECK_FALSE(A<B);
        CHECK_FALSE(C<A);
    
    }

        TEST_CASE("Testing Matrix <= Matrix"){
        
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat2,3,3);

        CHECK_FALSE(C<=A);   
        CHECK(A<=C);

    }

        TEST_CASE("Testing Matrix > Matrix"){
        
        vector<double>mat0={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        
        Matrix A = Matrix(mat0,3,3);
        Matrix B = Matrix(mat1,3,3);
        Matrix C = Matrix(mat2,3,3);


        CHECK_FALSE(A>C);   
        CHECK_FALSE(A>B);
        CHECK(C>A);
        CHECK(C>B);
        }


        TEST_CASE("Testing Matrix >= Matrix"){

        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat2,3,3);

        CHECK_FALSE(A>=C);   
        CHECK(C>=A);
        }


        TEST_CASE("input & output"){
        vector<double>mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
        vector<double>mat3={1, 0};
        
        Matrix A = Matrix(mat1,3,3);
        Matrix C = Matrix(mat3,1,2);
        
        

        }



