//return the sum of the maximum subarray in the given array
#include <bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int>& nums);

int main()
{
    vector<int> nums;
    int maxSum;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    maxSum = maximumSubarraySum(nums);
    cout << maxSum;

    nums = {1};
    maxSum = maximumSubarraySum(nums);
    cout << maxSum;

    nums = {5,4,-1,7,8};
    maxSum = maximumSubarraySum(nums);
    cout << maxSum;

    return 0;
}

//Brute force approach
int maximumSubarraySum(vector<int>& nums)
{
    int sum = 0;
    int maxi = INT_MIN;

    for(int i=0; i<nums.size(); ++i)
    {
        sum = 0;
        for(int j=i; j<nums.size(); ++j)
        {
            sum += nums[j];
            maxi = max(maxi,sum);
        }
    }

    return maxi;
}

//Optimized Approach
int maximumSubarraySum(vector<int>& nums)
{
    int sum = 0;
    int maxi = INT_MIN;

    for(int i=0; i<nums.size(); ++i)
    {
        sum += nums[i];
        maxi = max(maxi,sum);

        if(sum<0) sum=0;
    }

    return maxi;
}