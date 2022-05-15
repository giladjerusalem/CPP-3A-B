// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>
// using namespace std;

// #include "sources/Matrix.hpp"
// using namespace zich;

// int main() {
//     std::vector<double> arr1 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
//     std::vector<double> unit_matrix = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     std::vector<double> arr_b = {3, 0, 0, 0, 3, 0, 0, 0, 3};
//     std::vector<double> arr_c = {2, 0, 0, 0, 2, 0, 0, 0, 2};
//     std::vector<double> arr_d= {4, 0, 0, 0, 4, 0, 0, 0, 4};
//     std::vector<double> arr_e= {4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0};
//     std::vector<double> arr_f= {5, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0};
//     std::vector<double> arr_h= {9, 0, 0, 0, 9, 0, 0, 0, 9, 0, 0, 0};

//     std::vector<double> arr1_1 = {0, 1, 1, 1, 0, 1, 1, 1,0};
//     std::vector<double> unit_matrix_1 = {2, 1, 1, 1, 2, 1, 1, 1, 2};
//     std::vector<double> arr_b_1 = {4, 1, 1, 1, 4, 1, 1, 1, 4};
//     std::vector<double> arr_c_1 = {3, 1, 1, 1, 3, 1, 1, 1, 3};
//     std::vector<double> arr_d_1= {5, 1, 1, 1, 5, 1, 1, 1, 5};
//     std::vector<double> arr_e_1= {5, 1, 1, 1, 5, 1, 1, 1, 5, 1, 1, 1};
//     std::vector<double> arr_f_1= {6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1};
//     std::vector<double> arr_h_1= {10, 1, 1,1, 10, 1, 1, 1, 10, 1, 1, 1};

//     Matrix mat_un{arr1,3,3};
//     Matrix mat1{unit_matrix,3,3};
//     Matrix mat2{arr_b,3,3};
//     Matrix mat3{arr_c,3,3};
//     Matrix mat4{arr_d,3,3};
//     Matrix mat5{arr_e,4,3};
//     Matrix mat6{arr_f,4,3};
//     Matrix mat7{arr_h,4,3};
//     Matrix mat_un_1{arr1_1,3,3};
//     Matrix mat1_1{unit_matrix_1,3,3};
//     Matrix mat2_2{arr_b_1,3,3};
//     Matrix mat3_3{arr_c_1,3,3};
//     Matrix mat4_4{arr_d_1,3,3};
//     Matrix mat5_5{arr_e_1,4,3};
//     Matrix mat6_6{arr_f_1,4,3};
//     Matrix mat7_7{arr_h_1,4,3};
//     --mat_un_1;
//     --mat1_1;
//     --mat2_2;
//     --mat3_3;
//     --mat4_4;
//     --mat5_5;
//     --mat6_6;
//     --mat7_7;

//     Matrix mymat();
// //    cin >> mymat;
//     cout << "col and row : " << mymat << endl;
// //
// //    ostringstream os1;
// //    cout<<mat1<<endl;
// //    os1 << mat1;
// //    cout<<(os1.str() == "[1 0 0]\n[0 1 0]\n[0 0 1]")<<endl;
// //    mat2*=mat1;
// //    cout<<(mat2== mat2_2)<<endl;
// //    mat4*=mat1;
// //    cout<<(mat4 == mat4_4)<<endl;
// //    mat3*=mat1;
// //    cout<<(mat3 == mat3_3)<<endl;
// //    mat2*=mat3;
// //    cout<<(mat2 == mat3+mat4)<<endl;
// //    mat1*=3;
// //    cout<<(mat1 == mat2)<<endl;
// //    mat1-=mat3;
// //    mat1*=4;
// //    cout<<(mat4 == mat1)<<endl;
// //    mat1-=mat2;
// //    mat1*=2;
// //    cout<<(mat3 == mat1)<<endl;
// //    mat5*= 9;
// //    mat7*=4;
// //    cout<<(mat5 == mat7)<<endl;
// //    mat4*=9;
// //    CHECK_THROWS( equalto=(mat4*5 == mat5*4));
// //    cout<<(true,mat3>mat1)<<endl;
// //    cout<<(true,mat4>mat1)<<endl;
// //    cout<<(true,mat4>mat2)<<endl;
// //    cout<<(true,mat2>mat3)<<endl;
// //    cout<<(true,mat4>mat3)<<endl;
// //
// //    cout<<(true,mat6>mat5)<<endl;
// //    cout<<(true,mat7>mat6)<<endl;
// //    cout<<(true,mat7>mat5)<<endl;
// //    mat1+=mat3;
// //    cout<<(mat2==mat1)<<endl;
// //    mat2+=mat1;
// //    mat4+=mat3;
// //    cout<<(mat4==mat2)<<endl;
// //    mat1+=mat1;
// //    cout<<(mat1==mat2)<<endl;
// //    mat1+= mat3;
// //    mat3+= mat2;
// //    cout<<(mat3==mat1)<<endl;
// //    mat5+=mat6;
// //    cout<<(mat5==mat7)<<endl;

// //    CHECK_THROWS(mat5+=mat4);
// //    CHECK_THROWS(mat6+=mat4);
// //    CHECK_THROWS(mat7+=mat4);
// //    CHECK_THROWS(mat5+=mat3);
// //    CHECK_THROWS(mat6+=mat3);

// //    int k=1;
// //    int random = rand() % 1000;
// //    for (double i = 0; i < 2; i++) {
// //        vector<double> vec1 = {i * random, i * random, i * random, i * random, i * random, i * random, i * random,
// //                               i * random, i * random};
// //        Matrix matrix(vec1, 3, 3);
// //
// //        vector<double> v = {i * random, i * random, i * random, i * random, i * random, i * random, i * random,
// //                            i * random, i * random};
// //        Matrix matrix_v(v, 3, 3);
// //
// //        vector<double> vec = {i * random + k, i * random + k, i * random + k, i * random + k, i * random + k,
// //                              i * random + k, i * random + k, i * random + k, i * random + k};
// //        Matrix mat(vec, 3, 3);
// //
// //        vector<double> vec1_minus = {-i * random, -i * random, -i * random, -i * random, -i * random, -i * random,
// //                                     -i * random, -i * random, -i * random};
// //        Matrix matrix_minus(vec1_minus, 3, 3);
// //
// //        vector<double> vec_sub = {i * random - k, i * random, i * random, i * random, i * random - k, i * random,
// //                                  i * random, i * random, i * random - k};
// //        Matrix matrix_sub(vec_sub, 3, 3);
// //
// //        vector<double> vec_ = {i * random - k, i * random - k, i * random - k, i * random - k, i * random - k,
// //                               i * random - k, i * random - k, i * random - k, i * random - k};
// //        Matrix matrix_(vec_, 3, 3);
// //
// //        cout << (matrix++ == matrix_v) << endl;
// //        cout << (matrix-- == mat) << endl;
// //
// //        cout << (++matrix == mat) << endl;
// //        ++matrix;
// //        cout << (--matrix == mat) << endl;
// //    }

// //        vector<double> vec1 = {1,1,1,1};//2x2
// //        vector<double> vec2 = {2,2,2,2};//2x2
// //        Matrix mat(vec1, 2, 2);
// //        Matrix mat1(vec2, 2, 2);
// //        ++mat;
// //        cout << (++mat==mat1) << endl;


//     std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     std::vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
//     Matrix a{identity, 3, 3};  // constructor taking a vector and a matrix size
//     cout<<a.stri()<<endl;
//     cout << a << endl;
// //    /* prints [1 0 0]
// //              [0 1 0]
// //              [0 0 1]*/
// //
// //    cout << (-a) << endl;
// //    /* prints [-1 0 0]
// //              [0 -1 0]
// //              [0 0 -1]*/
// //    cout << (3*a) << endl;
// //    /* prints [3 0 0]
// //              [0 3 0]
// //              [0 0 3]*/
// //
// //    Matrix b{arr, 3, 3};
// //    a *= -3;
// //    cout << (a+b) << endl;  // prints the 0 matrix
// //    cout << (b-a) << endl;
// //    /* prints [6 0 0]
// //              [0 6 0]
// //              [0 0 6]*/
// //
//     cout << "End of demo!" << endl;
//     return 0;
// }




//////////////////////////////////////////////////////////////////////////////




// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>
// #include <string>
// #include <vector>
// using namespace std;
// #include "Matrix.hpp"
// using namespace zich;

// int main() 
// {
//     int length=0;
//     int width=0;
//     size_t i=0;
//     double num=0;
//     string command="0";
//     vector<double> arr;

//     while(true)
//     {
//         cout << "\nenter length\n";
//         cin >> length;
//         cout << "\nenter width\n";
//         cin >> width;

//         for(i=0; i<width*length; i++)
//         {
//             cout << "\nenter num to first matrix\n";
//             cin >> num;
//             arr.push_back(num);
//         }
//         Matrix a = Matrix(arr, length, width);

//         arr.clear();
//         for(i=0; i<width*length; i++)
//         {
//             cout << "\nenter num to second matrix\n";
//             cin >> num;
//             arr.push_back(num);
//         }
//         Matrix b = Matrix(arr, length, width);
//         arr.clear();

        

//         while(command != "*")
//         {
//             cout << "\n\nfirst matrix:\n" << a;
//             cout << "\n\nsecond matrix:\n" << b;
//             command.clear();
//             cout << "\n\nenter action to take (+ , - , +=, -= , * , = , == , != , < , >, ++, --) or ** to reset\n";
//             cin >> command;

//             if(command == "*")
//             {
//                 command.clear();
//                 break;
//             }

//             if(command == "+")
//             {
//                 cout << (a+b) <<"\n\n";
//             }

//             if(command == "-")
//             {
//                 cout << (a-b) <<"\n\n";
//             }

//             if(command == "+=")
//             {
//                 a+=b;
//             }

//             if(command == "-=")
//             {
//                 a-=b;
//             }
//             try
//             {
//                 if(command == "*")
//                 {
//                     cout << (a*b) <<"\n\n";
//                 }

//                 if(command == "*=")
//                 {
//                     a*=b;
//                 }
//             }
//             catch(const std::exception& e)
//             {
//                 std::cerr << e.what() << '\n';
//                 continue;
//             }
            
            

//             if(command == "==")
//             {
//                 cout << (a==b) << "\n\n";
//             }

//             if(command == "!=")
//             {
//                 cout << (a!=b) << "\n\n";
//             }

//             if(command == "<")
//             {
//                 cout << (a<b) << "\n\n";
//             }

//             if(command == ">")
//             {
//                 cout << (a>b) << "\n\n";
//             }

//             if(command == "++")
//             {
//                 a++;
//             }

//             if(command == "--")
//             {
//                 a--;
//             }

//         }
        




//     }
    

//     return 0;
// }


//////////////////////////////////////////////////////////////////////////////



/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 * 
 * Edited by Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Matrix.hpp"
using namespace zich;

int main() {
  
//   vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//   vector<double> arr = {-3, 1, 0, 0, -3, 0, 0, 0, -3};
//   vector<double> arr_bad = {1,1,1,1};
//   vector<double> mul = {3,1,4};
//   vector<double> mul2 = {4,3,2,5,6,8};

//   Matrix A{identity, 3, 3};  // constructor taking a vector and a matrix size
//   Matrix B{arr, 3, 3};
//   Matrix B2{arr, 3, 3};

//   Matrix BAD{arr_bad, 2, 2};

//   Matrix MUL{mul, 1, 3};
//   Matrix MUL2{mul2, 3, 2};

// cout<<(++A);
//   double d = -2.0;
//  (MUL*MUL2);
  //B<=A;
  //c = a+2.0;
  //cout << a << endl;
  prints [1 0 0]
            [0 1 0]
            [0 0 1]

 cout << (-a) << endl;
   prints [-1 0 0]
            [0 -1 0]
            [0 0 -1]
  cout << (3*a) << endl;
   prints [3 0 0]
            [0 3 0]
            [0 0 3]

   Matrix b{arr, 3, 3};
  a *= -3;
   cout << (a+b) << endl;  // prints the 0 matrix
   cout << (b-a) << endl;
   prints [6 0 0]
            [0 6 0]
            [0 0 6]

  cout << "End of demo!" << endl;

  

  return 0;
}

