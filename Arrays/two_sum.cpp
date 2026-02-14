#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> nums, int target);

int main()
{
    vector<int> nums;
    int target;
    vector<int> idx;

    nums = {2,7,11,15};
    target = 9;
    idx = twoSum(nums,target);
    cout << "[" << idx[0] << "," << idx[1] << "]" << endl;

    nums = {3,2,4};
    target = 6;
    idx = twoSum(nums,target);
    cout << "[" << idx[0] << "," << idx[1] << "]" << endl;

    nums = {3,3};
    target = 6;
    idx = twoSum(nums,target);
    cout << "[" << idx[0] << "," << idx[1] << "]" << endl;

    return 0;
}

//Brute force approach: O(n^2) time complexity
vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> ans(2,0);

    for(int i=0; i<nums.size()-1; ++i)
    {
        for(int j=i+1; j<nums.size(); ++j)
        {
            if(nums[i]+nums[j]==target)
            {
                ans[0] = i; ans[1] = j;
            }
        }
    }

    return ans;
}

//Better approach: Using hashing, O(N) time complexity
vector<int> twoSum(vector<int> nums, int target)
{
    unordered_map<int,int> mpp;

    for(int i=0; i<nums.size(); ++i)
    {
        if(mpp.find(target-nums[i])!=mpp.end())
        {
            return {mpp[target-nums[i]], i};
        }
        else 
            mpp[nums[i]] = i;
    }

    return {-1,-1};
}

//Optimal Approach: using two pointers, O(N log N) time complexity
vector<int> twoSum(vector<int> nums, int target)
{
    vector<pair<int,int>> numsWithIndex;

    for(int i=0; i<nums.size(); ++i)
        numsWithIndex.push_back({nums[i],i});

    sort(numsWithIndex.begin(),numsWithIndex.end());

    int left = 0; int right = nums.size()-1;
    for(int i=0; i<nums.size(); ++i)
    {
        if(numsWithIndex[left].first + numsWithIndex[right].first==target)
            return {numsWithIndex[left].second, numsWithIndex[right].second};
        else if(numsWithIndex[left].first + numsWithIndex[right].first<target)
            left++;
        else if(numsWithIndex[left].first + numsWithIndex[right].first>target)
            right--;
    }

    return {-1,-1};
}