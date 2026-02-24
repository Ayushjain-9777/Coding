#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows);
void show(vector<vector<int>> pascal);

int main()
{
    int n;
    vector<vector<int>> pascal;

    cin>>n;
    pascal = generate(n);
    show(pascal);

    return 0;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    for(int i=0; i<numRows; ++i) {
        vector<int> row(i+1,1);
        for(int j=1; j<i; ++j) {
            row[j] = pascal[i-1][j-1] + pascal[i-1][j]; 
        }
        pascal.push_back(row);
    }

    return pascal;
}

//Approach-2: Using binomial coefficients, C(n,k) = C(n,k-1)*(n-k+1)/k 
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    for(int i=0; i<numRows; ++i) {
        vector<int> row(i+1,1);

        for(int j=1; j<i; ++j) {
            row[j] = row[j-1]*(i+1-j)/j;
        }
        pascal.push_back(row);
    }

    return pascal;
}

void show(vector<vector<int>> pascal)
{
    for(int i=0; i<pascal.size(); ++i) {
        for(int j=0; j<pascal[i].size(); ++j) {
            cout<<pascal[i][j]<<" ";
        }
        cout<<endl;
    }
}