// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target);
void show(vector<int> nums, int target);

int main()
{
    vector<int> nums;
    int target;
    vector<int> result(2,-1);
    int first = 0, last = 1;

    nums = {5,7,7,8,8,10};
    target = 6;
    show(nums,target);
    result = searchRange(nums,target);
    cout<<"first is: "<<result[first]<<"\nlast is: "<<result[last]<<endl;
    cout<<endl;

    nums = {5,7,7,8,8,10};
    target = 8;
    show(nums,target);
    result = searchRange(nums,target);
    cout<<"first is: "<<result[first]<<"\nlast is: "<<result[last]<<endl;
    cout<<endl;

    nums = {};
    target = 0;
    show(nums,target);
    result = searchRange(nums,target);
    cout<<"first is: "<<result[first]<<"\nlast is: "<<result[last]<<endl;
    cout<<endl;

    return 0;
}

//Approach-1
vector<int> searchRange(vector<int>& nums, int target) {
    int low=0, high=nums.size()-1;
    int mid;
    bool flag = false;

    while(low<=high) {
        mid = (low+high)/2;
        if(nums[mid]==target) {
            flag = true;
            break;
        } else if(nums[mid]>target) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    while(flag && low<=high) {
        if(nums[low]!=target) low++;
        if(nums[high]!=target) high--;

        if(nums[low]==target && nums[high]==target) 
            return {low,high};
    }

    return {-1,-1};
}

//Approach-2 can be using two different functions to get the first and last occurence of the element using binary search
void show(vector<int> nums, int target)
{
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    cout<<"target is: "<<target<<endl;
}