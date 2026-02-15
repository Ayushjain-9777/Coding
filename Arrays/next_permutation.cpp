// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).
// Input: Arr[] = {1,3,2}
// Output: {2,1,3}
// Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums);

int main()
{
    vector<int> nums;

    nums = {1,2,3};
    nextPermutation(nums);
    for(int i=0; i<nums.size(); ++i)
        cout<<nums[i]<<"\t";
    cout<<endl;

    nums = {3,2,1};
    nextPermutation(nums);
    for(int i=0; i<nums.size(); ++i)
        cout<<nums[i]<<"\t";
    cout<<endl;

    nums = {2,1,3};
    nextPermutation(nums);
    for(int i=0; i<nums.size(); ++i)
        cout<<nums[i]<<"\t";
    cout<<endl;

    nums = {1,1,5};
    nextPermutation(nums);
    for(int i=0; i<nums.size(); ++i)
        cout<<nums[i]<<"\t";
    cout<<endl;

    nums = {2,3,1};
    nextPermutation(nums);
    for(int i=0; i<nums.size(); ++i)
        cout<<nums[i]<<"\t";
    cout<<endl;

    return 0;
}

//Using in-built function.
void nextPermutation(vector<int>& nums)
{
    next_permutation(nums.begin(),nums.end());
}


void nextPermutation(vector<int>& nums) {
    int index = -1;
    for(int i=nums.size()-2; i>=0; --i)
    {
        if(nums[i]<nums[i+1])   //breaking point
        {
            index = i;
            break;
        }
    }

    if(index==-1)   //No breaking point found
    {
        reverse(nums.begin(),nums.end());
        return;
    }

    for(int i=nums.size()-1; i>index; --i)
    {
        if(nums[i]>nums[index])
        {
            swap(nums[i],nums[index]);
            break;
        }
    }

    reverse(nums.begin()+index+1,nums.end());
}