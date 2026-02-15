// Problem Statement: Given an array nums of n integers.
// Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.
// Example 1:
// Input:
//  nums = [100, 4, 200, 1, 3, 2]  
// Output:
//  4  
// Explanation:
//  The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

// Example 2:
// Input:
//  nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
// Output:
//  9  
// Explanation:
//  The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.
#include <bits/stdc++.h>>
using namespace std;

int longestConsecutive(vector<int>& nums);

int main()
{
    vector<int> nums;
    int res;

    nums = {100, 4, 200, 1, 3, 2};
    res = longestConsecutive(nums);
    cout << res << endl;

    nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    res = longestConsecutive(nums);
    cout << res << endl;

    return 0;
}

//Approach-1: time complexity O(n log n), extra log n due to sorting function
int longestConsecutive(vector<int>& nums) {
    if(nums.size()<2) return nums.size();

    sort(nums.begin(),nums.end());
    int ans = 0; int cnt = 0;

    for(int i=0; i<nums.size()-1; ++i)
    {
        if(nums[i+1]==nums[i]+1 || nums[i+1]==nums[i])
        {
            if(nums[i+1]==nums[i]+1)
                cnt++;
        } else {
            cnt = 0;
        }

        ans = max(ans,cnt+1);
    }

    return ans;
}

//look for optimal approach