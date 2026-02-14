#include <bits/stdc++.h>
using namespace std;

vector<int> maximumSubarray(vector<int>& nums);

int main()
{
    vector<int> nums;
    vector<int> maxSum;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    maxSum = maximumSubarray(nums);
    for(int i = maxSum[0]; i<=maxSum[1]; ++i)
        cout << nums[i] << "\t";

    nums = {1};
    maxSum = maximumSubarray(nums);
    for(int i = maxSum[0]; i<=maxSum[1]; ++i)
        cout << nums[i] << "\t";

    nums = {5,4,-1,7,8};
    maxSum = maximumSubarray(nums);
    for(int i = maxSum[0]; i<=maxSum[1]; ++i)
        cout << nums[i] << "\t";

    return 0;
}

vector<int> maximumSubarray(vector<int>& nums)
{
    int sum = 0;
    int maxi = INT_MIN;
    int start = 0, end = -1;

    for(int i=0; i<nums.size(); ++i)
    {
        sum += nums[i];
        
        if(sum>maxi)
        {
            maxi = sum;
            end = i;
        }

        if(sum<0)
        {
            sum = 0;
            start = i+1;
            end = i+1;
        }
    }

    return {start,end};
}