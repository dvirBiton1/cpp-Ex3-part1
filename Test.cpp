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

// TEST_CASE("Good input")
// {

// }
// TEST_CASE("NOT THROW")
// {
// }
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
    Matrix A{vector1, 4, 4};
    Matrix B{vector2, 3, 3};
    CHECK_THROWS(A + B);
    CHECK_THROWS(B + A);
    CHECK_THROWS(A - B);
    CHECK_THROWS(B - A);
    CHECK_THROWS(A += B);
    CHECK_THROWS(B += A);
    CHECK_THROWS(A -= B);
    CHECK_THROWS(B -= A);
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
    Matrix A{vector1, 4, 4};
    Matrix B{vector2, 3, 3};
    CHECK_THROWS(A * B);
    CHECK_THROWS(B * A);
    CHECK_THROWS(A *= B);
    CHECK_THROWS(B *= A);
}


TEST_CASE("Equality between two matrix's")
{
    /**
     * Given 2 matrix's A and B
     * Matrix A and Matrix B will call equal if and only if all their numbers equals.
     * Matrix A will be called bigger than B if and only if the sum of the parts of A biggers then parts of B.
     * If matrix A and B not from the same shape (different rows and cols size)-an error should be thrown.
     * If the sum of A and B is equal but not all of their numbers are equal- A are not equal to B.
     */
    SUBCASE("Two equal matrix")
    {
        vector<double> vectorA = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<double> vectorB = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        Matrix A{vectorA, 3, 3};
        Matrix B{vectorB, 3, 3};
        CHECK_EQ(A == B, true);
        CHECK_EQ(A != B, false);
        CHECK_EQ(A < B, false);
        CHECK_EQ(A > B, false);
        CHECK_EQ(A <= B, true);
        CHECK_EQ(A >= B, true);
    }

    SUBCASE("A and B is in the same shape, but B is bigger")
    {
        vector<double> vectorA = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<double> vectorB = {9, 9, 9, 9, 9, 9, 9, 9, 9};
        Matrix A{vectorA, 3, 3};
        Matrix B{vectorB, 3, 3};
        CHECK_EQ(A == B, false);
        CHECK_EQ(A != B, true);
        CHECK_EQ(A < B, true);
        CHECK_EQ(A > B, false);
        CHECK_EQ(A <= B, true);
        CHECK_EQ(A >= B, false);
    }
    SUBCASE("A and B is in the same shape, but A is bigger")
    {
        vector<double> vectorA = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
        vector<double> vectorB = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        Matrix A{vectorA, 3, 4};
        Matrix B{vectorB, 3, 4};
        CHECK_EQ(A == B, false);
        CHECK_EQ(A != B, true);
        CHECK_EQ(A < B, false);
        CHECK_EQ(A > B, true);
        CHECK_EQ(A <= B, false);
        CHECK_EQ(A >= B, true);
        // Now we will multy B by 10 and A==B
        B = B * 10;
        CHECK_EQ(B == A, true);
    }
}