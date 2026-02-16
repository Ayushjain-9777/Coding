//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
#include <bits/stdc++.h>
using namespace std;

void putZeroes(vector<vector<int>>& matrix, int rowIdx, int colIdx);
void setZeroes(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> matrix;

    matrix = {{1,1,1},{1,0,1},{1,1,1}};
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=0; j<matrix[0].size(); ++j)
            cout << matrix[i][j] << "\t";
        cout<<endl;
    }
    setZeroes(matrix);
    cout<<endl;
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=0; j<matrix[0].size(); ++j)
            cout << matrix[i][j] << "\t";
        cout<<endl;
    }

    cout<<endl<<endl;
    
    matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=0; j<matrix[0].size(); ++j)
            cout << matrix[i][j] << "\t";
        cout<<endl;
    }
    setZeroes(matrix);
    cout<<endl;
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=0; j<matrix[0].size(); ++j)
            cout << matrix[i][j] << "\t";
        cout<<endl;
    }

    return 0;
}

void setZeroes(vector<vector<int>>& matrix) {
    vector<vector<int>> zeroes;
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=0; j<matrix[0].size(); ++j)
        {
            if(matrix[i][j]==0)
                zeroes.push_back({i,j});   
                //can't use putZeroes function here as it will create other zeroes in the original matrix and will generate wrong ansnwer 
        }
    }
    
    for(int i=0; i<zeroes.size(); ++i)
    putZeroes(matrix,zeroes[i][0],zeroes[i][1]);
}

void putZeroes(vector<vector<int>>& matrix, int rowIdx, int colIdx) {
    for(int i=0; i<matrix[0].size(); ++i)
        matrix[rowIdx][i] = 0;
    for(int i=0; i<matrix.size(); ++i)
        matrix[i][colIdx] = 0;
}