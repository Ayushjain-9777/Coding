#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix);
void show(vector<vector<int>> matrix);

int main()
{
    vector<vector<int>> matrix;

    matrix = {{1,2,3},{4,5,6},{7,8,9}};
    show(matrix);
    rotate(matrix);
    show(matrix);

    matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    show(matrix);
    rotate(matrix);
    show(matrix);

    return 0;
}

void rotate(vector<vector<int>>& matrix) {
    vector<int> first = matrix[0];
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=i; j<matrix.size(); ++j)  //transpose of the matrix
        {
            if(i==j) continue;
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
        reverse(matrix[i].begin(),matrix[i].end());     //reverse the row
    }
}

void show(vector<vector<int>> matrix)
{
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=0; j<matrix.size(); ++j)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}