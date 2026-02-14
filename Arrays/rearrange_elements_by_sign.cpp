// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// Constraints:

// 2 <= nums.length <= 2 * 105
// nums.length is even
// 1 <= |nums[i]| <= 105
// nums consists of equal number of positive and negative integers
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums);

int main()
{
    vector<int> nums;

    nums = {3,1,-2,-5,2,-4};
    nums = rearrangeArray(nums);
    for(int i=0; i<nums.size(); ++i)
        cout << nums[i] << "\t";
    cout << endl;

    nums = {-1,1};
    nums = rearrangeArray(nums);
    for(int i=0; i<nums.size(); ++i)
        cout << nums[i] << "\t";
    cout << endl;

    return 0;
}

vector<int> rearrangeArray(vector<int>& nums)
{
    vector<int> p1(nums.size()/2), p2(nums.size()/2);
    
}