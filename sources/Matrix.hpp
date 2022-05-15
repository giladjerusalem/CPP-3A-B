#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace zich
{
    class Matrix
    {
        vector<vector<double>> mat;

    public:
        Matrix(vector<double>, int, int);

        Matrix operator+(const Matrix &a); //
        Matrix operator-(const Matrix &a); //
        Matrix operator+(double num);
        Matrix &operator-(double num);
        Matrix &operator-(); // unery
        Matrix operator+(); // genery

        Matrix &operator++(); //
        Matrix &operator--();
        Matrix operator++(int);
        Matrix operator--(int);

        Matrix &operator+=(const Matrix &a);
        Matrix &operator-=(const Matrix &a);

        bool operator<(const Matrix &a) const;
        bool operator<=(const Matrix &a) const;
        bool operator>=(const Matrix &a) const;
        bool operator>(const Matrix &a) const;
        bool operator == (const Matrix &a) const;
        bool operator!=(const Matrix &a) const;

        Matrix operator*(const Matrix &a)const;
        Matrix operator*=(const Matrix &a);
        friend Matrix operator*(double, Matrix &a);
        Matrix operator*=(double);
        Matrix operator*(double) const;


        friend ostringstream &operator << (ostringstream &output, Matrix const &a);
        friend istringstream &operator >> (istringstream &input, Matrix &a);
    };
    Matrix operator*(double, Matrix const &a);

}
