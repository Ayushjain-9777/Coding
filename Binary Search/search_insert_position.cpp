// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> nums, int target);
void show(vector<int> nums, int target);

int main()
{
    vector<int> nums;
    int target, result;

    nums = {1,2,2,3};
    target = 2;
    show(nums,target);
    result = searchInsert(nums,target);
    if(result==nums.size()) cout<<"Index not found"<<endl<<endl;
    else cout<<"target found at index "<<result<<endl<<endl;

    nums = {3,5,8,15,19};
    target = 9;
    show(nums,target);
    result = searchInsert(nums,target);
    if(result==nums.size()) cout<<"Index not found"<<endl;
    else cout<<"target found at index "<<result<<endl;

    return 0;
}

int searchInsert(vector<int> nums, int target)
{
    int low=0, high = nums.size()-1;
    int mid; 
    int ans = nums.size();

    while(low<=high) {
        mid = (low+high)/2;
        if(nums[mid]>=target) {
            ans = mid;
            high = mid - 1;
        }    
        else
            low = mid+1;
    }
    return ans;
}

void show(vector<int> nums, int target)
{
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    cout<<"target is: "<<target<<endl;
}