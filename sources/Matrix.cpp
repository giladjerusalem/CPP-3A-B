#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Matrix.hpp"
#include <string>

using namespace std;
namespace zich
{

    Matrix::Matrix(vector<double> arr, int line, int col) // constructor
    {
        size_t z = 0;       // will run on arr  
        mat = vector<vector<double>>((size_t)line, vector<double>((size_t)col, 0)); // initial
        for (size_t i = 0; i < line; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                mat[i][j] = arr[z++];
                // cout<<mat[i][j];        
                // cout<<",";
            }
          //  cout<<endl;
        }  
    }

istringstream &operator >> (istringstream &input, Matrix &a) // input the matrix
    {   
        if(input.eof()) // if input is empty
        {
            throw invalid_argument("input cant be empty");
        }

        string str = string(1, input.get()); // string represent the value we put in a spesific cell.
        if(str != "[") // need to start with '['
        {
            throw invalid_argument("each raw start with '['");
        }
        str.clear();

        size_t rows=0;
        size_t colls=0;
        size_t colls_first_row=0;
        char c=0;        
        double num=0;
        bool first_row = true;
        vector<double> arr;

        while(!input.eof()) // go over the input untill it is over and put values in to array
        {
            c = input.get();
            if(c==' ') // represent new cell in the raw.
            {
                try
                {
                    arr.push_back(stod(str)); // new element to the array
                }
                catch(const std::exception& e)
                {
                    throw invalid_argument("invalid input");
                }
                colls++;
                str.clear();
            }
            else if(c == ']') // represent new row in the matrix.
            {
                try
                {
                    arr.push_back(stod(str)); // new element to the array
                }
                catch(const std::exception& e)
                {
                    throw invalid_argument("invalid input");
                }
                rows++;
                colls++;
                str.clear();
                if(first_row) // if this is the first raw we build
                {
                    colls_first_row = colls; // we now know how many cells each row need to have
                    first_row = false;
                }
                else if(colls != colls_first_row) // if the current raw has diferent number of cells in it then we throw error.
                {
                    throw invalid_argument("all raws need to have the same number of cells");
                }
    
                while(!input.eof() && c!='[')
                {
                    c = input.get();
                    str += string(1, c); 
                }

                if(input.eof() && str.size()==2)
                {
                    break;
                }
                if(str != ", [")
                {
                    throw invalid_argument("invalid input");
                }
                str.clear();
                colls = 0;
                continue;
            }
            str += string(1, c);
        }
        temp = Matrix(arr, rows, colls_first_row);
        return input;
    }


// ostringstream &operator << (ostringstream &output, Matrix const &a) // output the matrix -->supposed to work
//     {
//         size_t i=0;
//         size_t j=0;
//         for(i=0; i<a.mat[0].size(); i++) // run matrix rows
//         {
//             // output << "[";  //put [ at the beggining of every row
//             for(j=0; j<a.mat.size(); j++) // run matrix col's
//             {
//                 output << a.mat[i][j];  //print the cell
//                 if(j == a.mat.size()-1) 
//                 {
//                     output << "]";  //close row with ]
//                 }
//                 else
//                 {
//                     output << " ";  //put space between cell except the last cell - there we need just ]
//                 }
//             }
//             if(i != a.mat[0].size()-1) 
//             {
//                 output << endl;     //put end line between rows except the last row
//             }
//         }
//         return output;
//     }





}