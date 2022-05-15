#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Matrix.hpp"
using namespace zich;

int main() {
    vector<double> mat1={1, 0, 0, 0, 1, 0, 0, 0, 1};
    vector<double> mat2={3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double> mat3={1, 0};
    vector<double> mat4={1, 0, 0};

    Matrix A = Matrix(mat1,3,3);
    Matrix B = Matrix(mat2,3,3);
    Matrix C = Matrix(mat3,1,2);
    Matrix D = Matrix(mat4,1,3);

    double num =1;
    double num2=2;
    
    ostringstream stream;
    
    stream<<(A);
    stream<<"\n\n";
    stream<<(B);
    stream<<"\n\n";
    stream<<(num);
    stream<<"\n\n";
    stream<<(num2);
    stream<<"\n\n";

    stream<<"print A+B\n";
    stream<<(A+B);
    stream<<"\n\n";

    stream<<"print A-B\n";
    stream<<(A-B);
    stream<<"\n\n";
 
    stream<<"print A+=B\n";
    stream<<(A+=B);
    stream<<"\n\n";
    
    stream<<"print A-=B\n";
    stream<<(A-=B);
    stream<<"\n\n";
    
    stream<<"print A++\n";
    stream<<(A++);
    stream<<"\n\n";
    
    stream<<"print A--\n";
    stream<<(++A);
    stream<<"\n\n";
    
    stream<<"print A--\n";
    stream<<(A--);
    stream<<"\n\n";
    
    stream<<"print --A\n";
    stream<<(--A);
    stream<<"\n\n";

    stream<<"print A+num\n";
    stream<<(A+num);
    stream<<"\n\n";

    stream<<"print A-num\n";
    stream<<(A-num);
    stream<<"\n\n";

    stream<<"print +A(unery): \n";
    stream<<(+A);
    stream<<"\n\n";
    
    stream<<"print A<B \n";
    stream<<(A<B);
    stream<<"\n\n";

    stream<<"print A>B \n";
    stream<<(A>B);
    stream<<"\n\n";
    
    stream<<"print A<=B \n";
    stream<<(A<=B);
    stream<<"\n\n";
    
    stream<<"print A>=B \n";
    stream<<(A>B);
    stream<<"\n\n";
    
    stream<<"print A==B \n";
    stream<<(A==B);
    stream<<"\n\n";;

    stream<<"print A!=B \n";
    stream<<(A!=B);
    stream<<"\n\n";

    stream<<"print A*B \n";
    stream<<(A*B);
    stream<<"\n\n";

    stream<<"print A*=B \n";
    stream<<(A*=B);
    stream<<"\n\n";

    stream<<"print num2*A \n";
    stream<<(num2*A);
    stream<<"\n\n";



    cout<<stream.str();


    return 0;
}