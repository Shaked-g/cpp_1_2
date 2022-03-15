#include "mat.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
const int HIGEST_ASCII = 126;
const int LOWEST_ASCII = 33;

namespace ariel {
    // Recives column by Row
    string mat(int col, int row, char symbol1, char symbol2){
        if ( row%2 == 0 || col%2 == 0 ){
            throw "Invalid input number";
        }
        if ( row < 0 || col < 0 ){
            throw "not accepting negetive numbers";
        }
        // Only accepting chars within (33, 126)
        if ( LOWEST_ASCII > symbol1 || symbol1 > HIGEST_ASCII ){
            throw "symbol 1 out of accepted range";
        }
        if ( LOWEST_ASCII > symbol2 || symbol2 > HIGEST_ASCII ){
            throw "symbol 2 out of accepted range";
        }
        

        int i = 0;
        int rowStart = 0; // Starting row index
        int colStart = 0; // Starting column index
        int rowCopy = row; // Ending row index
        int colCopy = col; // Ending column index
    
        vector<vector<char>> mat (row,vector<char> (col));
        char currSymbol = symbol1;
    
        /**
         * Goes over the vector mat in spiral pattern.
         * With every interation fills a ractangle with
         * one of the symbols
         * as mat[row][col]
         */
        while (rowStart < row && colStart < col) {
            // Fill the first row
            for (i = colStart; i < col; ++i) {

                mat[rowStart][i] = currSymbol;
            }
            rowStart++;
    
            // Fill the last column
            for (i = rowStart; i < row; ++i) {
                mat[i][col-1] = currSymbol;
            }
            col--;
    
            // Fill the last row
            if (rowStart < row) {
                for (i = col-1; i >= colStart; --i){
                    mat[row-1][i] = currSymbol;
                }
                row--;
            }
    
            // Fill first column
            if (colStart < col) {
                for (i = row-1; i >= rowStart; --i){
                    mat[i][colStart] = currSymbol;
                }
                colStart++;
            }
    
            // Change symbol on end of every iteration
            if (currSymbol == symbol2){
                currSymbol = symbol1;
            }
            else {
                currSymbol = symbol2;
            }
        }

        // Building return string
        string str;
        for (i = 0; i < rowCopy; i++)
        {
            for (int j = 0; j < colCopy; j++){
                str += mat[i][j];
            }
            str += "\n";
        }
        return str;
    }
}