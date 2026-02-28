#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
void show(vector<int> nums);

int main()
{
    int m,n;
    vector<int> nums1, nums2;

    m = 3, n = 3;
    nums1 = {1,2,3,0,0,0};
    show(nums1);
    nums2 = {2,5,6};
    show(nums2);
    merge(nums1,m,nums2,n);
    cout<<endl;
    show(nums1);

    m = 0, n = 1;
    nums1 = {0};
    show(nums1);
    nums2 = {1};
    show(nums2);
    merge(nums1,m,nums2,n);
    cout<<endl;
    show(nums1);

    m = 1, n = 0;
    nums1 = {1};
    show(nums1);
    nums2 = {};
    show(nums2);
    merge(nums1,m,nums2,n);
    cout<<endl;
    show(nums1);

    return 0;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int ptr1 = m-1;
    int ptr2 = n-1;
    int idx = m+n-1;

    while(idx>=0) {
        if(ptr2<0) break;
        if(ptr1<0) {
            nums1[idx] = nums2[ptr2];
            idx--, ptr2--;
            continue;
        }
        if(nums1[ptr1]>nums2[ptr2]) {
            nums1[idx] = nums1[ptr1];
            idx--, ptr1--;
        } else { //nums1[ptr1]<=nums2[ptr2]
            nums1[idx] = nums2[ptr2];
            idx--, ptr2--;
        }
    }
}

void show(vector<int> nums)
{
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
}