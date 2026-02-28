#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> nums);

int main()
{
    vector<int> nums;
    int result;

    nums = {2,3,-2,4};
    result = maxProduct(nums);
    cout<<result<<endl;
    
    return 0;
}

//Brute force Approach
int maxProduct(vector<int> nums) {
    int prod = 1;
    int maxi = 0;
    
    for(int i=0; i<nums.size(); ++i) {
        prod = 1;
        for(int j=i; j<nums.size(); ++j) {
            prod *= nums[j];
            maxi = max(maxi,prod);
        }
    }
    
    return maxi;
}

//Better Approach
int maxProduct(vector<int> nums) {
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    int n = nums.size();

    for(int i=0; i<n; ++i) {
        if(pre==0) pre = 1;
        if(suff==0) suff = 1;

        pre *= nums[i];
        suff *= nums[n-i-1];

        ans = max(ans,max(pre,suff));
    }

    return ans;
}