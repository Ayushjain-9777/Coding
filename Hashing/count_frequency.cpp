#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};

    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
    }

    unordered_map<int,int> mpp;

    for(int i=0; i<n; ++i)
    {
        mpp[arr[i]]++;
    }

    for(auto pair: mpp)
        cout << pair.first << " -> " << pair.second << endl;

    return 0;
}