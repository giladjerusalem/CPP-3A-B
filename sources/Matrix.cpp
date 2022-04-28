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
        if (arr.size() != line * col)
        {
            throw(invalid_argument("size array not valid."));
        }
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


    
    Matrix Matrix::operator+(const Matrix &a)
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0;
        for (i = 0; i < mat.size(); i++)
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat.at(i).at(j) + a.mat.at(i).at(j); // put the result in arr
                z++;
            }
        }
        Matrix A(arr, mat.size(), mat[0].size()); // put arr in new matrix
        return A;
    }

    Matrix Matrix::operator+(double num)
    {
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0; // will run on arr
        for (i = 0; i < mat.size(); i++)
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j] + num; // put the result in arr
                z++;
            }
            
        }
        Matrix A(arr, mat.size(), mat[0].size()); // put arr in new matrix
        return A;
    }

    Matrix Matrix::operator+()
    {                                                      // multiply in 1
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j] * (1); // multiply in 1 and put in arr
                z++;
            }
            
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the informaton in matrix
        return *this;
    }
    
    Matrix Matrix::operator-(const Matrix &a)
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0;
        for (i = 0; i < mat.size(); i++)
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j] - a.mat[i][j];
                z++;
            }
           
        }
        Matrix A(arr, mat.size(), mat[0].size()); // put arr in new matrix
        return A;
    }

    Matrix &Matrix::operator-(double num)
    {
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0; // will run on arr
        for (i = 0; i < mat.size(); i++)
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j] - num; // put the result in arr
                z++;
            }
            
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put arr in new matrix
        return *this;
    }

    Matrix &Matrix::operator-()
    {                                                      // multiply in -1
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j] * (-1); // multiply in -1 and put in arr
                z++;
            }
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the informaton in matrix
        return *this;
    }


    Matrix &Matrix::operator+=(const Matrix &a)
    {
        if (this->mat.size() != a.mat.size() || this->mat.at(0).size() != a.mat.at(0).size ())
        {
            throw invalid_argument("Both matritions must have same number of lines and col");
        }
        size_t i = 0;
        size_t j = 0;
        for ( i = 0; i < mat.size(); i++) 
        {
            for ( j = 0; j < mat.at(0).size(); j++)
            {
                this->mat.at(i).at(j) = mat.at(i).at(j) + a.mat.at(i).at(j);    // sum mat with a.mat 
            }
        }
        return *this;
    }  

    Matrix &Matrix::operator-=(const Matrix &a)
    {
        if (this->mat.size() != a.mat.size() || this->mat.at(0).size() != a.mat.at(0).size ())
        {
            throw invalid_argument("Both matritions must have same number of lines and col");
        }
        size_t i = 0;
        size_t j = 0;
        for ( i = 0; i < mat.size(); i++) 
        {
            for ( j = 0; j < mat.at(0).size(); j++)
            {
                this->mat.at(i).at(j) = mat.at(i).at(j) - a.mat.at(i).at(j);    // sum mat with a.mat 
            }
        }
        return *this;
    } 

    Matrix &Matrix::operator++()
    {                                                      //++num and return Matrix after change
        vector<double> arr; // initial the vector
        size_t i = 0;
        size_t j = 0;
        for (i = 0; i < mat.size(); i++)
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                arr.push_back(mat[i][j] + 1); // put in arr the number in mat and add 1
            }
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the informaton in matrix
        return *this;
    }

    Matrix &Matrix::operator--()
    {                                                      //--num and return Matrix after change
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j] - 1; // put in arr the number in mat and add 1
                z++;
            }
            
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the informaton in matrix
        return *this;
    }

    Matrix Matrix::operator++(int)
    {              
        vector<double> copy;
        size_t rows = mat.size();    
        size_t cols = mat.at(0).size();  
        size_t i = 0;
        size_t j = 0;                                      
        for(i=0; i< rows; i++)
        {
            for(j=0; j< cols; j++)
            {
                copy.push_back(mat.at(i).at(j));
            }
        }
        // num-- and return Matrix before change
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector  
        size_t z = 0;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                arr[z] = mat[i][j]+1; // put in arr the original values of mat  
                z++;
            }
          
        }
    *this = Matrix(arr, rows, cols); // put the original values in matrix and return
    return Matrix(copy, rows, cols);
    }

    Matrix Matrix::operator--(int)
    {              
        vector<double> copy;
        size_t rows = mat.size();    
        size_t cols = mat.at(0).size();  
        size_t i = 0;
        size_t j = 0;                                      
        for(i=0; i< rows; i++)
        {
            for(j=0; j< cols; j++)
            {
                copy.push_back(mat.at(i).at(j));
            }
        }
        // num-- and return Matrix before change
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector  
        size_t z = 0;
        for ( i = 0; i < rows; i++)
        {
            for ( j = 0; j < cols; j++)
            {
                arr[z] = mat[i][j]-1; // put in arr the original values of mat  
                z++;
            }
          
        }
    *this = Matrix(arr, rows, cols); // put the original values in matrix and return
    return Matrix(copy, rows, cols);
    }



    Matrix Matrix::operator*(double num) const
    {                                                      // run on cells and multyplay in num and put it in new matrix
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0; // will run on arr
        for (i = 0; i < mat.size(); i++)
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j] * num; // put the result in arr
                z++;
            }
        }
        return Matrix(arr, mat.size(), mat[0].size()); // put arr in new matrix
    }
    
    Matrix Matrix::operator*=(double num)
    {                                                      // need to update the matrix
        size_t i = 0;
        size_t j = 0;
        for (i = 0; i < mat.size(); i++) // mat[i][j] = mat[i][j]*num; //update the matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                //cout<<mat[i][j]<<endl;        //print before
                mat[i][j] = mat[i][j] * num; //*num
                //cout<<mat[i][j]<<endl;        //print after
            }
        }
        return *this; // put arr in new matrix

    }
       
    
    bool Matrix::operator == (const Matrix &a) const
    {
        if (mat.size() != a.mat.size() || mat.at(0).size() != a.mat.at(0).size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        size_t i = 0;
        size_t j = 0;
        bool flag = true;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat.at(0).size(); j++)
            {
                if (this->mat.at(i).at(j) != a.mat.at(i).at(j))
                {
                    flag = false;
                    return flag;
                }
            }
        }
        return flag;
    }


    bool Matrix::operator!=(const Matrix &a) const
    {
        return !(*this == a);
    }
     
    bool Matrix::operator<(const Matrix &a) const
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        size_t i = 0;
        size_t j = 0;
        double sum = 0;
        double sum_a = 0;
        bool flag = true;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                sum = sum + mat[i][j];
                sum_a = sum_a + a.mat[i][j];
            }
        }
        if (sum >= sum_a) // if sum of mat >= sum of a.mat -> return false
        {
            flag = false;
            return flag;
        }
        return flag;
    }

    bool Matrix::operator>(const Matrix &a) const
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        size_t i = 0;
        size_t j = 0;
        double sum = 0;
        double sum_a = 0;
        bool flag = true;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                sum = sum + mat[i][j];
                sum_a = sum_a + a.mat[i][j];
            }
        }
        if (sum <= sum_a) // if sum of mat <= sum of a.mat -> return false
        {
            flag = false;
            return flag;
        }
        return flag;
    }

    bool Matrix::operator>=(const Matrix &a) const
    {
       if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        size_t i = 0;
        size_t j = 0;
        double sum = 0;
        double sum_a = 0;
        bool flag = true;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                sum = sum + mat[i][j];
                sum_a = sum_a + a.mat[i][j];
            }
        }
        if (sum < sum_a) // if sum of mat < sum of a.mat -> return false
        {
            flag = false;
            return flag;
        }
        return flag;
    }

    bool Matrix::operator<=(const Matrix &a) const
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        size_t i = 0;
        size_t j = 0;
        double sum = 0;
        double sum_a = 0;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                sum = sum + mat[i][j];
                sum_a = sum_a + a.mat[i][j];
            }
        }
        return (!(sum > sum_a)); // if sum of mat > sum of a.mat -> return false
    }


    Matrix Matrix::operator*(const Matrix &a) const
    {                                      // not change the matrix
        if (mat[0].size() != a.mat.size()) // if the mat-col != from a.mat-line its not possible to multyply.
        {
            throw invalid_argument("The col of the left mat must be equal to the line of right mat -> for example: 3x2 2x3");
        }
        size_t i = 0;
        size_t k = 0;
        size_t j = 0;
        double sum = 0;
        vector<double> arr(mat.size() * a.mat[0].size(), 0); // define vector with size of line*col
        Matrix res = Matrix(arr, mat.size(), a.mat[0].size());
        for (i = 0; i < mat.size(); i++)                  // mat-> col ++
        {
            for (k = 0; k < a.mat[0].size(); k++) // a.mat-> line ++
            {
                for (j = 0; j < a.mat.size(); j++) // a.mat-> col ++
                {
                    sum = sum + (mat[i][j] * a.mat[j][k]); // will double line with all col of the other matrix
                }
                res.mat[i][k] = sum;// sum each cell in col*line
                //cout<<sum<<endl;
                sum = 0;
            }
        }
        return res;
    }

    Matrix Matrix::operator*=(const Matrix &a) 
    {                                      // change the matrix
        if (mat[0].size() != a.mat.size()) // if the mat-col != from a.mat-line its not possible to multyply.
        {
            throw invalid_argument("The col of the left mat must be equal to the line of right mat -> for example: 3x2 2x3");
        }
        size_t i = 0;
        size_t k = 0;
        size_t j = 0;
        double sum = 0;
        vector<double> arr(mat.size() * a.mat[0].size(), 0); // define vector with size of line*col
        Matrix res = Matrix(arr, mat.size(), a.mat[0].size());
        for (i = 0; i < mat.size(); i++)                  // mat-> col ++
        {
            for (k = 0; k < a.mat[0].size(); k++) // a.mat-> line ++
            {
                for (j = 0; j < a.mat.size(); j++) // a.mat-> col ++
                {
                    sum = sum + (mat[i][j] * a.mat[j][k]); // will double line with all col of the other matrix
                }
                res.mat[i][k] = sum;// sum each cell in col*line
                sum = 0;
            }
        }
        mat=res.mat;    //mat point to res memory
        return *this;
    }

    Matrix operator*(double num, Matrix &a)
    {
       return a*num;
    }
    
    ostringstream &operator << (ostringstream &output, Matrix const &a) // output the matrix -->supposed to work
    {
        size_t i=0;
        size_t j=0;
        for(i=0; i<a.mat[0].size(); i++) // run matrix rows
        {
            output << "[";  //put [ at the beggining of every row
            for(j=0; j<a.mat.size(); j++) // run matrix col's
            {
                output << a.mat[i][j];  //print the cell
                
                if(j == a.mat.size()-1) 
                {
                    output << "]";  //if reach the end --> close with ]
                }
                else
                {
                    output << " ";  //put space between cells
                }
            }
            if(i != a.mat[0].size()-1) 
            {
                output << endl;     //put end line between rows except the last row
            }
        }

        return output;
    }
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////



    istringstream &operator >> (istringstream &input, Matrix &a) // input operator >> of the matrix
    {
        if(input.eof()) // if empty input
        {
            throw ("input must look like matrix ");
        }

        string str = string(1, input.get()); // get the char from input and convert to string
        if(!(str == "[")) // first cell must start with [
        {
            throw ("row must start with [ ");
        }
        str.clear();    //first - clear the string
        
        //define variables
        vector<double> arr;
        char ch=0;
        size_t first_row=0;
        size_t row=0;
        size_t col=0;
        bool start_row = true;

        while(!input.eof()) // run while the input is not finished 
        {
            ch = input.get();
            if(ch==' ') 
            {
                arr.push_back(stod(str));   // push new element to arr and cast to double
                col++;
                str.clear();
            }
            else if(ch == ']') // sign of finishing the row and start the new one
            {
                arr.push_back(stod(str));   // push new element to arr and cast to double
                col++;
                row++;
                str.clear();
                if(start_row)   // if we build the first row
                {
                    first_row = col; // cause all rows must be in the same size
                    start_row = false;
                }
                while(!input.eof() && ch!='[')
                {
                    ch = input.get();
                    str += string(1, ch);   // get the char and convert to string
                }
                if(input.eof() && str.size()==2)
                {
                    break;
                }
                if(str != ", [")
                {
                    throw ("wrong input");
                }
                str.clear();
                col = 0;
                continue;
            }
            str += string(1, ch); // get the char and convert to string
        }
        a = Matrix(arr, row, first_row);
        return input;
    }
}