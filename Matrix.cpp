#include "Matrix.hpp"
namespace zich
{

    Matrix::Matrix(const vector<double> &data, const int row, const int col)
    {
        if (row <= 0 || col <= 0)
        {
            throw runtime_error("row or col can't be negative");
        }
        if (data.size() != row * col)
        {
            throw runtime_error("the array must be equal to the size of the matrix");
        }

        this->data = data;
        this->row = row;
        this->col = col;
    }
    Matrix::~Matrix()
    {
    }

    Matrix Matrix::operator+(Matrix const &mat)
    {
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and col must be equal");
        }
        vector<double> mat3_data;
        // Matrix mat3(row, col);
        mat3_data.resize((unsigned int)(row * col));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat3_data[(unsigned int)(i * col + j)] = this->data[(unsigned int)(i * col + j)] + mat.data[(unsigned int)(i * col + j)];
            }
        }
        Matrix mat3(mat3_data, this->row, mat.col);
        return mat3;
    }
    Matrix &Matrix::operator++()
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                this->data[(unsigned int)(i * col + j)] += 1;
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
                this->data[(unsigned int)(i * col + j)] += 1;
            }
        }
        return copy;
    }
    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and col must be equal");
        }
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                this->data[(unsigned int)(i * col + j)] += mat.data[(unsigned int)(i * col + j)];
            }
        }
        return *this;
    }
    Matrix Matrix::operator-(const Matrix &mat)
    {
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and col must be equal");
        }
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(row * col));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat3_data[(unsigned int)(i * col + j)] = this->data[(unsigned int)(i * col + j)] - mat.data[(unsigned int)(i * col + j)];
            }
        }
        Matrix mat3(mat3_data, this->row, mat.col);
        return mat3;
    }
    Matrix &Matrix::operator--()
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                this->data[(unsigned int)(i * col + j)] -= 1;
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
                this->data[(unsigned int)(i * col + j)] -= 1;
            }
        }
        return copy;
    }
    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and col must be equal");
        }
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                this->data[(unsigned int)(i * col + j)] -= mat.data[(unsigned int)(i * col + j)];
            }
        }
        return *this;
    }
    double Matrix::multiplication(const Matrix &mat, const int tempRow, const int tempCol)
    {
        double sum = 0;
        for (int i = 0; i < this->col; i++)
        {
            // cout<< this->data[(unsigned int)(this->col * tempRow + i)] << " " << mat.data[(unsigned int)(mat.col * i + tempCol)]<<endl;
            sum += this->data[(unsigned int)(this->col * tempRow + i)] * mat.data[(unsigned int)(mat.col * i + tempCol)];
        }
        return sum;
    }
    Matrix Matrix::operator*(const Matrix &mat)
    {
        if (this->col != mat.row)
        {
            throw runtime_error("the cols must be equal");
        }
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(this->row * mat.col));
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                mat3_data[(unsigned int)(i * mat.col + j)] = multiplication(mat, i, j);
            }
        }
        Matrix mat3(mat3_data, this->row, mat.col);
        return mat3;
    }
    Matrix &Matrix::operator*=(const Matrix &mat)
    {
        if (this->col != mat.row)
        {
            throw runtime_error("the cols must be equal");
        }
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(this->row * mat.col));
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                mat3_data[(unsigned int)(i * mat.col + j)] = multiplication(mat, i, j);
            }
        }
        this->col = mat.col;
        this->data = mat3_data;
        return *this;
    }

    Matrix Matrix::operator*(const double scalar)
    {
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(row * col));
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                if (this->data[(unsigned int)(i * this->col + j)] == 0)
                {
                    continue;
                }
                mat3_data[(unsigned int)(i * this->col + j)] = this->data[(unsigned int)(i * this->col + j)] * scalar;
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
                if (this->data[(unsigned int)(i * this->col + j)] == 0)
                {
                    continue;
                }
                this->data[(unsigned int)(i * this->col + j)] *= scalar;
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
                sum += this->data[(unsigned int)(i * col + j)];
            }
        }
        return sum;
    }
    bool Matrix::operator>(Matrix &mat)
    {
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and cols must be equals");
        }
        return this->sumMatrix() > mat.sumMatrix();
    }
    bool Matrix::operator>=(Matrix &mat)
    {
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and cols must be equals");
        }
        return this->sumMatrix() >= mat.sumMatrix();
    }
    bool Matrix::operator<(Matrix &mat)
    {
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and cols must be equals");
        }
        return this->sumMatrix() < mat.sumMatrix();
    }
    bool Matrix::operator<=(Matrix &mat)
    {
        if (this->row != mat.row || this->col != mat.col)
        {
            throw runtime_error("row and cols must be equals");
        }
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
                if (this->data[(unsigned int)(i * col + j)] != mat.data[(unsigned int)(i * col + j)])
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
                if (this->data[(unsigned int)(i * col + j)] != mat.data[(unsigned int)(i * col + j)])
                {
                    return true;
                }
            }
        }
        return false;
    }
    ostream &operator<<(ostream &out, const Matrix &mat)
    {
        for (int i = 0; i < mat.row; i++)
        {
            out << '[';
            for (int j = 0; j < mat.col; j++)
            {
                if (j != mat.col - 1)
                {
                    out << mat.data[(unsigned int)(i * mat.col + j)] << ' ';
                }
                else
                {
                    out << mat.data[(unsigned int)(i * mat.col + j)];
                }
            }
            out << ']' << '\n';
        }
        return out;
    }
    vector<string> split(string str, char seperator)
    {
        int len = str.length();
        string temp;
        vector<string> vec;
        for (int i = 0; i < len; i++)
        {
            if (str[(unsigned int) i] == seperator)
            {
                vec.push_back(temp);
                temp = "";
            }
            else
            {
                if (str[(unsigned int)i] == '[' || str[(unsigned int)i] == ']')
                {
                    continue;
                }
                    temp += str[(unsigned int)i];
            }
        }
        vec.push_back(temp);
        return vec;
    }
    istream &operator>>(istream &input, Matrix &mat)
    {
        char ch = 0;
        string s;
        while (ch != '\n')
        {
            ch = input.get();
            s += ch;
        }
        vector<string> vs = split(s, ',');
        int row = vs.size();
        int len1 = vs.size();
        int col = 0;
        int flag = 1;
        vector<string> vs2;
        vector<double> vd;
        for (int i = 0; i < len1; i++)
        {
            vs2 = split(vs[(unsigned int)i], ' ');
            int len2 = vs2.size();
            if (flag == 1)
            {
                col = len2;
                flag = 0;
            }
            if (col != len2)
            {
                throw runtime_error("you have problem with your string");
            }

            for (int j = 0; j < len2; j++)
            {
                vd.push_back(stod(vs2[(unsigned int)j]));
            }
        }
        mat.data = vd;
        mat.row = row;
        mat.col = col;
        return input;
    }
    Matrix operator-(Matrix &mat)
    {
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(mat.row * mat.col));
        for (int i = 0; i < mat.row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                if (mat.data[(unsigned int)(i * mat.col + j)] == 0)
                {
                    continue;
                }
                mat3_data[(unsigned int)(i * mat.col + j)] = (-1) * mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        Matrix mat3(mat3_data, mat.row, mat.col);
        return mat3;
    }
    Matrix operator+(Matrix &mat)
    {
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(mat.row * mat.col));
        for (int i = 0; i < mat.row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                if (mat.data[(unsigned int)(i * mat.col + j)] == 0)
                {
                    continue;
                }
                mat3_data[(unsigned int)(i * mat.col + j)] = mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        Matrix mat3(mat3_data, mat.row, mat.col);
        return mat3;
    }
    Matrix operator*(const double scalar, Matrix &mat)
    {
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(mat.row * mat.col));
        for (int i = 0; i < mat.row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                if (mat.data[(unsigned int)(i * mat.col + j)] == 0)
                {
                    continue;
                }
                mat3_data[(unsigned int)(i * mat.col + j)] = scalar * mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        Matrix mat3(mat3_data, mat.row, mat.col);
        return mat3;
    }
}

//  Matrix::Matrix(/* args */)
//  {
//  }

//  Matrix::~Matrix()
//  {
//  }