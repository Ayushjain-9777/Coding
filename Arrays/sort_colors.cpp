// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> nums);

int main()
{

}

//Brute force approach: counting frequencies of 0, 1, and 2, and make changes in the array according to the frequency. 
void sortColors(vector<int> nums)
{
    int cnt0=0, cnt1=0;

    for(int i=0; i<nums.size(); ++i)
    {
        if(nums[i]==0)
            cnt0++;
        else if(nums[i]==1)
            cnt1++;    
    }

    for(int i=0; i<nums.size(); ++i)
    {
        if(cnt0!=0)
        {
            nums[i] = 0;
            cnt0--;
            continue;
        } else if(cnt1!=0) {
            nums[i] = 1;
            cnt1--;
            continue;
        }
        else {
            nums[i] = 2;
        }
    }
}

//Optimal Approach: Using low, mid, and high
void sortColors(vector<int> nums)
{
    int low=0, mid=0, high=nums.size()-1;

    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low],nums[mid]);
            low++; mid++;
        }
        else if(nums[mid]==2)
        {
            swap(nums[mid],nums[high]);
            high--;
        } else if(nums[mid]==1) mid++;
    }
}