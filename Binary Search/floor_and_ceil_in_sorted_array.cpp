//you're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1]. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x
#include <bits/stdc++.h>
using namespace std;

vector<int> floorCeil(vector<int> nums, int x);
void show(vector<int> nums, int x);

int main()
{
    vector<int> nums;
    int x;
    vector<int> result(2,-1);
    int floor = 0, ceil = 1;

    nums = {3,4,4,7,8,10};
    x = 5;
    show(nums,x);
    result = floorCeil(nums,x);
    cout<<"Floor is: "<<result[floor]<<"\nCeil is: "<<result[ceil]<<endl;
    cout<<endl;

    nums = {3,4,4,7,8,10};
    x = 8;
    show(nums,x);
    result = floorCeil(nums,x);
    cout<<"Floor is: "<<result[floor]<<"\nCeil is: "<<result[ceil]<<endl;
    cout<<endl;

    return 0;
}

//Approach-1: Linear Search
vector<int> floorCeil(vector<int> nums, int x)
{
    int floor = -1, ceil = -1;

    for(int i=0; i<nums.size(); ++i) {
        if(nums[i]<x) {
            floor = nums[i];
        } else if(nums[i]>x) {
            ceil = nums[i];
            break;
        } else { //nums[i]==x
            floor = nums[i];
            ceil = nums[i];
            break;
        }
    }

    return {floor,ceil};
}

//Approach-2: Two different binary search loops for floor and ceil  
vector<int> floorCeil(vector<int> nums, int x)
{
    int floor = -1, ceil = -1;
    int low = 0, high = nums.size()-1;
    int mid;

    while(low<=high) {
        mid = (low+high)/2;
        if(nums[mid]==x) {
            floor = nums[mid];
            ceil = nums[mid];
            return {floor,ceil};
        } else if(nums[mid]<x) {
            floor = nums[mid];
            low = mid+1;
        } else { //nums[mid]>x
            high = mid-1;
        }
    }

    low = 0, high = nums.size()-1;  //setting up low and high again for second loop

    while(low<=high) {
        mid = (low+high)/2;
        if(nums[mid]>x) {
            ceil = nums[mid];
            high = mid-1;
        } else { //nums[mid]<=x, but equal is not possible, otherwise the function would have returned the answer from above loop
            low = mid+1;
        }
    }
    
    return {floor,ceil};
}

//Approach-3 can be using two different functions, one for finding the floor and the other for finding the ceil

void show(vector<int> nums, int x)
{
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    cout<<"x is: "<<x<<endl;
}