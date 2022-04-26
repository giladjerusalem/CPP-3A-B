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
        wide = line;
        length = col;
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
        wide = line;
        length = col;
        
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
                arr[z] = mat[i][j] + a.mat[i][j]; // put the result in arr
                cout<<arr[z]<<endl;
            }
            z++;
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
                cout<<arr[z]<<endl;
            }
            z++;
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
                cout<<arr[z]<<endl;
            }
            z++;
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
                cout<<arr[z]<<endl;
            }
            z++;
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the informaton in matrix    
        return *this;
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
                cout<<arr[z]<<endl;
            }
            z++;
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
                cout<<arr[z]<<endl;
            }
            z++;
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the informaton in matrix
        return *this;
    }


    Matrix &Matrix::operator+=(const Matrix &a)
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat.size())
        {
            throw invalid_argument("Both matritions must have same number of lines and col");
        }
        size_t i = 0;
        size_t j = 0;
        for ( i = 0; i < mat.size(); i++) // for changing the current mat
        {
            for ( j = 0; j < mat[0].size(); j++)
            {
                mat[i][j] = mat[i][j] + a.mat[i][j]; // decrease a.mat[i][j]
                cout<<mat[i][j]<<endl;            
            }
        }
        return *this;
    }  

    Matrix &Matrix::operator-=(const Matrix &a)
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat.size())
        {
            throw invalid_argument("Both matritions must have same number of lines and col");
        }
        size_t i = 0;
        size_t j = 0;
        for ( i = 0; i < mat.size(); i++) // for changing the current mat
        {
            for ( j = 0; j < mat[0].size(); j++)
            {
                mat[i][j] = mat[i][j] - a.mat[i][j]; // decrease a.mat[i][j]
                cout<<mat[i][j]<<endl;            
            }
        }
        return *this;
    }

    Matrix &Matrix::operator++()
    {                                                      //++num and return Matrix after change
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j] + 1; // put in arr the number in mat and add 1
                cout<<arr[z];
                cout<<",";
            }
            z++;
        }
        cout<<endl;
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
                cout<<arr[z];
                cout<<",";
            }
            z++;
            cout<<endl;
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the informaton in matrix
        return *this;
    }

    Matrix &Matrix::operator++(int)
    {                                                      // num++ and return Matrix before change
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0;
        cout<<"mat before change"<<endl;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j]; // put in arr the original values of mat
                cout<<arr[z];
                cout<<",";
            }
            z++;
        }
                cout<<endl<<"mat after change"<<endl;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[0].size(); j++)
            {
                mat[i][j] = mat[i][j] + 1; // add 1 to all cells in mat
                cout<<mat[i][j];
                cout<<",";
            }
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the original values in matrix and return
        return *this;
    }

    Matrix &Matrix::operator--(int)
    {                                                      // num-- and return Matrix before change
        vector<double> arr(mat.size() * mat[0].size(), 0); // initial the vector
        size_t i = 0;
        size_t j = 0;
        size_t z = 0;
        cout<<endl<<"mat before change"<<endl;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[0].size(); j++)
            {
                arr[z] = mat[i][j]; // put in arr the original values of mat
                cout<<arr[z];
                cout<<",";           }
            z++;
        }
        cout<<endl<<"mat after change"<<endl;
        for (size_t i = 0; i < mat.size(); i++)
        {
            for (size_t j = 0; j < mat[0].size(); j++)
            {
                mat[i][j] = mat[i][j] - 1; // add 1 to all cells in mat
                cout<<mat[i][j];
                cout<<",";           }
        }
        *this = Matrix(arr, mat.size(), mat[0].size()); // put the original values in matrix and return
        return *this;
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
                //cout<<arr[z]<<endl;
            }
            z++;
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
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        size_t i = 0;
        size_t j = 0;
        bool flag = true;
        cout<<"operator == "<<endl;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] != a.mat[i][j])
                {
                    cout<<"failed: "<<mat[i][j]<<" --> != --> "<<a.mat[i][j]<<endl;
                    flag = false;
                    return flag;
                }
               cout<<mat[i][j]<<" --> == --> "<<a.mat[i][j]<<endl;
            }
        }
        return flag;
    }


    bool Matrix::operator!=(const Matrix &a) const
    {
        if (mat.size() != a.mat.size() || mat[0].size() != a.mat[0].size())
        {
            throw invalid_argument("Both matrix must have same number of line and col");
        }
        size_t i = 0;
        size_t j = 0;
        bool flag = false;
        cout<<"operator != "<<endl;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] != a.mat[i][j]) // if in one place != then they not equal
                {
                    cout<<"true: "<<mat[i][j]<<"--> != -->"<<a.mat[i][j]<<endl;
                    flag = true;
                    return flag;
                }
            }
        }
        return flag;
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
        cout<<"operator <"<<endl;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                sum = sum + mat[i][j];
                sum_a = sum_a + a.mat[i][j];
            }
        }
        cout<<sum<<" < "<<sum_a<<" ? "<<endl;
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
        cout<<"operator >"<<endl;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                sum = sum + mat[i][j];
                sum_a = sum_a + a.mat[i][j];
            }
        }
        cout<<sum<<" > "<<sum_a<<" ? "<<endl;
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
        cout<<"operator >= "<<endl;
        for (i = 0; i < mat.size(); i++) // run on all cells in matrix
        {
            for (j = 0; j < mat[0].size(); j++)
            {
                sum = sum + mat[i][j];
                sum_a = sum_a + a.mat[i][j];
            }
        }
        cout<<sum<<" >= "<<sum_a<<" ? "<<endl;
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
        cout<<"operator <= "<<endl;
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
        cout<<sum<<" <= "<<sum_a<<" ? "<<endl;
        if (sum > sum_a) // if sum of mat > sum of a.mat -> return false
        {
            return false;
        }
        return true;
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
        vector<double> arr(mat.size() * mat[0].size(), 0); // define vector with size of line*col
        Matrix res = Matrix(arr, mat[0].size(), a.mat.size());
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
        return *this;
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
        vector<double> arr(mat.size() * mat[0].size(), 0); // define vector with size of line*col
        Matrix res = Matrix(arr, mat[0].size(), a.mat.size());
        for (i = 0; i < mat.size(); i++)                  // mat-> col ++
        {
            for (k = 0; k < a.mat[0].size(); k++) // a.mat-> line ++
            {
                for (j = 0; j < a.mat.size(); j++) // a.mat-> col ++
                {
                    sum = sum + (mat[i][j] * a.mat[j][k]); // will double line with all col of the other matrix
                }
                res.mat[i][k] = sum;// sum each cell in col*line
                cout<<sum<<endl;
                sum = 0;
            }
        }
        mat=res.mat;    //mat point to res memory
        return *this;
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////



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
                {clang --version
                    output << "]";  //close row with ]
                }
                else
                {
                    output << " ";  //put space between cell except the last cell - there we need just ]
                }
            }
            if(i != a.mat[0].size()-1) 
            {
                output << endl;     //put end line between rows except the last row
            }
        }
        return output;
    }

    // istream &operator>>(istream &input, const Matrix &temp)
    // {
    //     size_t i = 0;
    //     size_t j = 0;
    //     for (i = 0; i < temp.mat.size(); i++) // run all cells in matrix
    //     {
    //         for (j = 0; j < temp.mat[0].size(); j++)
    //         {
    //         }
    //     }
    //     return input;
    // }


    //mat.size()=width -------- mat[0].size()=length


    istringstream &operator >> (istringstream &input, Matrix &temp) // input of the matrix

    {
        if(input.eof // if empty input
        {
            throw invalid_argument("input must look mlike matrix ");
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

}