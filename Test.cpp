/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Dvir Biton>
 *
 * Date: 2021-02
 */

#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace zich;

TEST_CASE("Good input")
{
    SUBCASE(" * with identity")
    {
    vector<double> identity1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};// identity matrix 3*3
    vector<double> identity3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};// identity*3 matrix 3*3   
    Matrix identity{identity1, 3, 3};
    Matrix mat3_identity{identity3, 3, 3};
    CHECK_MESSAGE((identity * mat3_identity == mat3_identity) == true, "\noutput:\n"
                                                         << (identity * mat3_identity) << "expected:\n"
                                                         << mat3_identity);
    CHECK_MESSAGE((mat3_identity * identity == mat3_identity) == true, "\noutput:\n"
                                                         << (mat3_identity * identity) << "expected:\n"
                                                         << mat3_identity);
    }
    SUBCASE(" *= ")
    {
    vector<double> mat3v = {1, 2, 3, 4, 5, 6}; // matrix 2*3
    vector<double> mat4v = {1, 2, 3, 4, 5, 6}; // matrix 3*2
    vector<double> mat3_4v = {22,28,49,64}; // matrix 2*2
    Matrix mat3(mat3v,2,3);
    Matrix mat4(mat4v,3,2);
    Matrix mat3_4(mat3_4v,2,2);
    CHECK_MESSAGE((mat3 * mat4 == mat3_4) == true, "\noutput:\n"
                                                         << (mat3 * mat4) << "expected:\n"
                                                         << mat3_4);
    mat3 *= mat4;
    CHECK_MESSAGE((mat3 == mat3_4) == true, "\noutput:\n"
                                                         << (mat3) << "expected:\n"
                                                         << mat3_4);
    }
    SUBCASE(" +, ++ , +=  ")
    {
    vector<double> mat3v = {1, 2, 3, 4}; // matrix 2*2
    vector<double> mat4v = {1, 2, 3, 4}; // matrix 2*2
    vector<double> mat3_4v = {2,4,6,8}; // matrix 2*2
    vector<double> mat3_4_1v = {3,5,7,9}; // matrix 2*2
    Matrix mat3(mat3v,2,2);
    Matrix mat4(mat4v,2,2);
    Matrix mat3_4(mat3_4v,2,2);
    Matrix mat3_4_1(mat3_4_1v,2,2);
    CHECK_MESSAGE((mat3 + mat4 == mat3_4) == true, "\noutput:\n"
                                                         << (mat3 + mat4) << "expected:\n"
                                                         << mat3_4);
    mat3 += mat4;
    CHECK_MESSAGE((mat3 == mat3_4) == true, "\noutput:\n"
                                                         << (mat3) << "expected:\n"
                                                         << mat3_4);
    mat3_4++;                                                     
    CHECK_MESSAGE((mat3_4 == mat3_4_1) == true, "\noutput:\n"
                                                         << (mat3_4) << "expected:\n"
                                                         << mat3_4_1);
    }
    SUBCASE(" -, -- , -=  ")
    {
    vector<double> mat3v = {1, 2, 3, 4}; // matrix 2*2
    vector<double> mat4v = {1, 2, 3, 4}; // matrix 2*2
    vector<double> mat3_4v = {0,0,0,0}; // matrix 2*2
    vector<double> mat3_4_1v = {-1,-1,-1,-1}; // matrix 2*2
    Matrix mat3(mat3v,2,2);
    Matrix mat4(mat4v,2,2);
    Matrix mat3_4(mat3_4v,2,2);
    Matrix mat3_4_1(mat3_4_1v,2,2);
    CHECK_MESSAGE((mat3 - mat4 == mat3_4) == true, "\noutput:\n"
                                                         << (mat3 - mat4) << "expected:\n"
                                                         << mat3_4);
    mat3 -= mat4;
    CHECK_MESSAGE((mat3 == mat3_4) == true, "\noutput:\n"
                                                         << (mat3) << "expected:\n"
                                                         << mat3_4);
    mat3_4--;                                                     
    CHECK_MESSAGE((mat3_4 == mat3_4_1) == true, "\noutput:\n"
                                                         << (mat3_4) << "expected:\n"
                                                         << mat3_4_1);
    }
    SUBCASE(" scalar *, *=  ")
    {
    vector<double> mat3v = {1, 2, 3, 4}; // matrix 2*2
    vector<double> mat4v = {1, 2, 3, 4}; // matrix 2*2
    vector<double> mat3_4v = {2,4,6,8}; // matrix 2*2
    Matrix mat3(mat3v,2,2);
    Matrix mat4(mat4v,2,2);
    Matrix mat3_4(mat3_4v,2,2);
    CHECK_MESSAGE((mat3 * 2 == mat3_4) == true, "\noutput:\n"
                                                         << (mat3 * 2) << "expected:\n"
                                                         << mat3_4);
    mat4 *= 2;
    CHECK_MESSAGE((mat4 == mat3_4) == true, "\noutput:\n"
                                                         << (mat3) << "expected:\n"
                                                         << mat3_4);
    }
}

TEST_CASE("bad input +, -, +=, -= ")
{
    /*
    matrix a and matrix b are not equal in the size.
    in +, -, the rows and the cols must be equal.
    and the array we push must be same size as the rows*cols.
    */
    vector<double> vector1;
    for (double i = 0; i < 16; ++i)
    {
        vector1.push_back(i);
    }
    vector<double> vector2;
    for (double i = 0; i < 9; ++i)
    {
        vector2.push_back(i);
    }
    Matrix a{vector1, 4, 4};
    Matrix b{vector2, 3, 3};
    CHECK_THROWS(a + b);
    CHECK_THROWS(b + a);
    CHECK_THROWS(a - b);
    CHECK_THROWS(b - a);
    CHECK_THROWS(a += b);
    CHECK_THROWS(b += a);
    CHECK_THROWS(a -= b);
    CHECK_THROWS(b -= a);
}
TEST_CASE("bad input *, *=, ")
{
    /*
    in *, *= we need the mat1.col == mat2.row.
    and the array we push must be same size as the rows*cols.
    */
    vector<double> vector1;
    for (double i = 0; i < 16; ++i)
    {
        vector1.push_back(i);
    }
    vector<double> vector2;
    for (double i = 0; i < 9; ++i)
    {
        vector2.push_back(i);
    }
    Matrix a{vector1, 4, 4};
    Matrix b{vector2, 3, 3};
    CHECK_THROWS(a * b);
    CHECK_THROWS(b * a);
    CHECK_THROWS(a *= b);
    CHECK_THROWS(b *= a);
}

TEST_CASE("cheak operator >, >=, <, <= , ==, !=")
{
    SUBCASE("same matrix")
    {
        vector<double> vector1;
        for (double i = 0; i < 9; ++i)
        {
            vector1.push_back(i);
        }
        vector<double> vector2;
        for (double i = 0; i < 9; ++i)
        {
            vector2.push_back(i);
        }
        Matrix a{vector1, 3, 3};
        Matrix b{vector2, 3, 3};
        CHECK_EQ(a > b, false);
        CHECK_EQ(a >= b, true);
        CHECK_EQ(a < b, false);
        CHECK_EQ(a <= b, true);
        CHECK_EQ(a == b, true);
        CHECK_EQ(a != b, false);
    }

    SUBCASE("a and b same size but differnt values(b have bigger values)")
    {
        vector<double> vector1;
        for (double i = 0; i < 9; ++i)
        {
            vector1.push_back(i);
        }
        vector<double> vector2;
        for (double i = 0; i < 9; ++i)
        {
            vector2.push_back(9);
        }
        Matrix a{vector1, 3, 3};
        Matrix b{vector2, 3, 3};
        CHECK_EQ(a > b, false);
        CHECK_EQ(a >= b, false);
        CHECK_EQ(a < b, true);
        CHECK_EQ(a <= b, true);
        CHECK_EQ(a == b, false);
        CHECK_EQ(a != b, true);
    }
    SUBCASE("a and b NOT same size, expect throw excp ")
    {
        vector<double> vector1;
        for (double i = 0; i < 9; ++i)
        {
            vector1.push_back(i);
        }
        vector<double> vector2;
        for (double i = 0; i < 16; ++i)
        {
            vector2.push_back(9);
        }
        Matrix a{vector1, 3, 3};
        Matrix b{vector2, 4, 4};
        bool trow_exep;
        int numOfExcep = 0;
        try
        {
            trow_exep = a == b;
        }
        catch (const std::exception &)
        {
            numOfExcep++;
        }
        try
        {
            trow_exep = a >= b;
        }
        catch (const std::exception &)
        {
            numOfExcep++;
        }
        try
        {
            trow_exep = a <= b;
        }
        catch (const std::exception &)
        {
            numOfExcep++;
        }
        try
        {
            trow_exep = a != b;
        }
        catch (const std::exception &)
        {
            numOfExcep++;
        }
        try
        {
            trow_exep = a > b;
        }
        catch (const std::exception &)
        {
            numOfExcep++;
        }
        try
        {
            trow_exep = a < b;
        }
        catch (const std::exception &)
        {
            numOfExcep++;
        }
        if (numOfExcep == 6)
            CHECK_MESSAGE(true, "you get all the excep you need!");
    }
}
TEST_CASE("constrctor"){
    vector<double> vector1;
        for (double i = 0; i < 9; ++i)
        {
            vector1.push_back(i);
        }
        vector<double> vector2;
        for (double i = 0; i < 9; ++i)
        {
            vector2.push_back(i);
        }
        CHECK_NOTHROW(Matrix a(vector1, 3, 3));
        CHECK_THROWS(Matrix b(vector2, 4, 3));
}
