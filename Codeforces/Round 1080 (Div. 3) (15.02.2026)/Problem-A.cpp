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
        bool flag1 = false; //flag2 = false;
        for(int i=0; i<n; ++i)
            cin>>arr[i];
        
        for(int i=0; i<n-1; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(arr[i]*arr[j]==67)
                    flag1 = true;
            }
        }

        if(flag1==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        // for(int i=0; i<n; ++i)
        // {
        //     if(arr[i]==1)
        //         flag1 = true;
        //     if(arr[i]==67)
        //         flag2 = true;
        // }
        // if(flag1==true && flag2==true)
        //     cout<<"YES"<<endl;
        // else 
        //     cout<<"NO"<<endl;
    }
}