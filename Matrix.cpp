#include "Matrix.hpp"
using namespace zich;

Matrix::Matrix(const vector<double> data, const int row, const int col)
{
    if (row <= 0 || col <= 0)
    {
        throw runtime_error("row or col can't be negative");
    }

    this->data = data;
    this->row = row;
    this->col = col;
}

Matrix Matrix::operator+(const Matrix &mat)
{
    if (this->row != mat.row || this->col != mat.row)
    {
        throw runtime_error("row and col must be equal");
    }
    vector<double> mat3_data;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat3_data[size_t(i * col + j)] = mat.data[size_t(i * col + j)] + this->data[size_t(i * col + j)];
        }
    }
    Matrix mat3(mat3_data, row, col);
    return mat3;
}
Matrix &Matrix::operator++()
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[size_t(i * col + j)] += 1;
        }
    }
    return *this;
}
Matrix Matrix::operator++(const int num)
{
    Matrix copy = *this;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[size_t(i * col + j)] += 1;
        }
    }
    return copy;
}
Matrix &Matrix::operator+=(const Matrix &mat)
{
    if (this->row != mat.row || this->col != mat.row)
    {
        throw runtime_error("row and col must be equal");
    }
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[size_t(i * col + j)] += mat.data[size_t(i * col + j)];
        }
    }
    return *this;
}
Matrix Matrix::operator-(const Matrix &mat)
{
    if (this->row != mat.row || this->col != mat.row)
    {
        throw runtime_error("row and col must be equal");
    }
    vector<double> mat3_data;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            mat3_data[size_t(i * col + j)] = mat.data[size_t(i * col + j)] - this->data[size_t(i * col + j)];
        }
    }
    Matrix mat3(mat3_data, row, col);
    return mat3;
}
Matrix &Matrix::operator--()
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[size_t(i * col + j)] -= 1;
        }
    }
    return *this;
}
Matrix Matrix::operator--(const int num)
{
    Matrix copy = *this;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[size_t(i * col + j)] -= 1;
        }
    }
    return copy;
}
Matrix &Matrix::operator-=(const Matrix &mat)
{
    if (this->row != mat.row || this->col != mat.row)
    {
        throw runtime_error("row and col must be equal");
    }
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[size_t(i * col + j)] -= mat.data[size_t(i * col + j)];
        }
    }
    return *this;
}
double Matrix::multiplication(const Matrix &mat, const int tempRow, const int tempCol)
{
    double sum = 0;
    for (int i = 0; i < mat.col; i++)
    {
        sum += this->data[size_t(this->col * tempRow + i)] * mat.data[size_t(mat.col * i + tempCol)];
    }
    return sum;
}
Matrix Matrix::operator*(const Matrix &mat)
{
    if (this->col != mat.col)
    {
        throw runtime_error("the cols must be equal");
    }
    vector<double> mat3_data;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {

            mat3_data[size_t(i * this->col + j)] = multiplication(mat, i, j);
        }
    }
    Matrix mat3(mat3_data, this->row, mat.col);
    return mat3;
}
Matrix &Matrix::operator*=(const Matrix &mat)
{
    if (this->col != mat.col)
    {
        throw runtime_error("the cols must be equal");
    }
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            this->data[size_t(i * this->col + j)] *= multiplication(mat, i, j);
        }
    }
    return *this;
}

Matrix Matrix::operator*(const double scalar)
{
    vector<double> mat3_data;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {

            mat3_data[size_t(i * this->col + j)] *= scalar;
        }
    }
    Matrix mat3(mat3_data, this->row, this->col);
    return mat3;
}
Matrix &Matrix::operator*=(const double scalar)
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->data[size_t(i * this->col + j)] *= scalar;
        }
    }
    return *this;
}
double Matrix::sumMatrix()
{
    double sum = 0;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            sum += this->data[size_t(i * col + j)];
        }
    }
    return sum;
}
bool Matrix::operator>(Matrix &mat)
{
    return this->sumMatrix() > mat.sumMatrix();
}
bool Matrix::operator>=(Matrix &mat)
{
    return this->sumMatrix() >= mat.sumMatrix();
}
bool Matrix::operator<(Matrix &mat)
{
    return this->sumMatrix() < mat.sumMatrix();
}
bool Matrix::operator<=(Matrix &mat)
{
    return this->sumMatrix() <= mat.sumMatrix();
}
bool Matrix::operator==(Matrix &mat)
{
    if (this->row != mat.row || this->col != mat.col)
    {
        throw runtime_error("row and cols must be equals");
    }
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            if (this->data[size_t(i * col + j)] != mat.data[size_t(i * col + j)])
            {
                return false;
            }
        }
    }
    return true;
}
bool Matrix::operator!=(Matrix &mat)
{
    if (this->row != mat.row || this->col != mat.col)
    {
        throw runtime_error("row and cols must be equals");
    }
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            if (this->data[size_t(i * col + j)] != mat.data[size_t(i * col + j)])
            {
                return true;
            }
        }
    }
    return false;
}
ostream& operator<<(ostream &output, const Matrix& mat){
    for (int i = 0; i < mat.row; i++)
    {
        output << '[';
        for (int j = 0; j < mat.col; j++)
        {   
            if (j != mat.col )
            {
                output << mat.data[size_t(i * mat.col + j)] << ' ';
            }
            else{
                output <<mat.data[size_t(i * mat.col + j)];
            }
        }
        output << ']' << '\n';
    }
    return output;
    
}

//  Matrix::Matrix(/* args */)
//  {
//  }

//  Matrix::~Matrix()
//  {
//  }
