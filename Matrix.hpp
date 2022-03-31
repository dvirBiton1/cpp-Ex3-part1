#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

namespace zich
{
    class Matrix
    {
    public:
        int row;
        int col;
        vector<double> data;

    // public:
        Matrix(const vector<double> data, const int row, const int col);
        // ~Matrix();
        Matrix operator+(const Matrix &mat);
        Matrix& operator++();
        Matrix operator++(const int num);
        Matrix& operator+=(const Matrix &mat);

        Matrix operator-(const Matrix &mat);
        Matrix& operator--();
        Matrix operator--(const int num);
        Matrix& operator-=(const Matrix &mat);

        Matrix operator*(const Matrix &mat);
        Matrix& operator*=(const Matrix &mat);

        Matrix operator*(const double scalar);
        Matrix& operator*=(const double scalar);

        bool operator>(Matrix &mat);
        bool operator>=(Matrix &mat);
        bool operator<(Matrix &mat);
        bool operator<=(Matrix &mat);
        bool operator==(Matrix &mat);
        bool operator!=(Matrix &mat);
        double multiplication(const Matrix &mat, const int tempRow, const int tempCol);
        double sumMatrix();
        // friend ostream& operator<<(ostream& output, const Matrix& mat);
        friend ostream& operator<< (ostream& output, const Matrix& mat);
        friend istream& operator>> (istream &os , Matrix& mat);
        friend Matrix operator-(Matrix &mat);
        friend Matrix operator*(const double scalar, Matrix &mat);
    };

    //  Matrix::Matrix(/* args */)
    //  {
    //  }

    //  Matrix::~Matrix()
    //  {
    //  }

}