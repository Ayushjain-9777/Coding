#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums);

int main()
{
    int single;

    vector<int> nums = {2,2,1};
    single = singleNumber(nums);
    cout << single << endl;

    vector<int> nums = {4,1,2,1,2};
    single = singleNumber(nums);
    cout << single << endl;

    vector<int> nums = {1};
    single = singleNumber(nums);
    cout << single << endl;

    return 0;
}


//My Approach-1: Sort the given array, then check frequency count, the moment you get an element with freq only 1, return the element.
int singleNumber(vector<int>& nums) {
    if(nums.size()==1) return nums[0];

    int freq = 1;
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size()-1; ++i)
    {
        if(nums[i]!=nums[i+1])
        {
            if(freq==1)
                return nums[i];
            freq = 1;
        }
        else 
            freq++;
    }

    return nums[nums.size()-1];
}

//My Approach-2: Getting frequency using a map, but less better approach, takes more time complexity than first approach
int singleNumber(vector<int>& nums) {
    unordered_map<int,int> single;

    for(int i=0; i<nums.size(); ++i) {
            single[nums[i]]++;
    }

    for(int i=0; i<nums.size(); ++i) {
        if(single[nums[i]]==1) return nums[i];
    }

    return -1;
}

//Best Approach: O(1) space complexity
int singleNumber(vector<int>& nums) {
    // xor operation has two properties:-
    // 1. xor of same elements results in 0, i.e., a^a = 0.
    // 2. xor of a element with 0 result in the element, i.e., a^0 = a.
    // Since each element appears twice, and only one element is single, each pair of same elements will cancel out each other and only the single element remains.
    int xorr = 0;

    for(int i=0; i<nums.size(); ++i)
        xorr = xorr^nums[i];
    
    return xorr;
}