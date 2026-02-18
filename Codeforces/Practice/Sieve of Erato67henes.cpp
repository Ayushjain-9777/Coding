#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; ++i) {
            cin>>arr[i];
        }

        bool flag = false;

        for(int i=0; i<n; ++i) {
            if(arr[i]==67) {
                flag = true;
                break;
            }
        }

        if(flag==true)
            cout << "YES" << endl;
        else    
            cout << "NO" << endl;
    }

    return 0;
}