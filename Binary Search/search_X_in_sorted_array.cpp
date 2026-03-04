#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target);
void show(vector<int> nums, int target);

int main()
{
    vector<int> nums;
    int target, result;

    nums = {-1,0,3,5,9,12};
    target = 9;
    show(nums,target);
    result = search(nums,target);
    if(result==-1) cout<<"Index not found"<<endl<<endl;
    else cout<<"Target found at index "<<result<<endl<<endl;

    nums = {-1,0,3,5,9,12};
    target = 2;
    show(nums,target);
    result = search(nums,target);
    if(result==-1) cout<<"Index not found"<<endl;
    else cout<<"Target found at index "<<result<<endl;

    return 0;
}

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    int mid;

    while(low<=high) {
        mid = (low+high)/2;
        if(nums[mid]==target) {
            return mid;
        }
        else if(nums[mid]<target) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}

void show(vector<int> nums, int target)
{
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    cout<<"Target is: "<<target<<endl;
}