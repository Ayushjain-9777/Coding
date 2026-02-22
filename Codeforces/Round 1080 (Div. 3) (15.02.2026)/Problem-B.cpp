#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; ++i)
            cin>>arr[i];
        
        for(int i=0; i<n/2; ++i)
        {
            if(arr[i]!=i+1)
            {
                int j = i+1;
                int j2 = 2*j;
                swap(arr[j-1],arr[j2 - 1]);
            }
        }

        bool flag = true;

        for(int i=0; i<n; ++i)
        {
            if(arr[i]>arr[i+1])
            {
                flag = false;
                break;
            }
        }

        if(flag==true)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
}