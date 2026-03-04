//The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than to a given key i.e. x.
// The upper bound is the smallest index, ind, where arr[ind] > x. But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array.
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> nums, int key);
void show(vector<int> nums, int key);

int main()
{
    vector<int> nums;
    int key, result;

    nums = {1,2,2,3};
    key = 2;
    show(nums,key);
    result = upperBound(nums,key);
    if(result==nums.size()) cout<<"Index not found"<<endl<<endl;
    else cout<<"key found at index "<<result<<endl<<endl;

    nums = {3,5,8,15,19};
    key = 9;
    show(nums,key);
    result = upperBound(nums,key);
    if(result==nums.size()) cout<<"Index not found"<<endl;
    else cout<<"key found at index "<<result<<endl;

    return 0;
}

//Approach-1: Linear search
int upperBound(vector<int> nums, int key)
{
    for(int i=0; i<nums.size(); ++i) {
        if(nums[i]>key) return i;
    }
    return nums.size();
}

//Approach-2: Binary Search
int upperBound(vector<int> nums, int key)
{
    int low=0, high = nums.size()-1;
    int mid;
    int ans = nums.size();
    while(low<=high) {
        mid = (low+high)/2;
        if(nums[mid]<=key) low = mid+1;
        else {
            ans = mid;
            high = mid-1;
        }
    }
    return ans;
}

void show(vector<int> nums, int key)
{
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    cout<<"key is: "<<key<<endl;
}