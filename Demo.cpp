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
