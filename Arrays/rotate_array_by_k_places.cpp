//Rotate array to the right by k places
#include <bits/stdc++.h>
using namespace std;

//My approach
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dup(n);
    
    if(k>n) k = k%n;

    for(int i=0; i<n; ++i)
    {
        dup[i] = nums[(n+i-k)%n];
    }
    for(int i=0; i<n; ++i)
        nums[i] = dup[i];
    
}

//Better approach: O(1) space complexity
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    rotate(nums,k);

    return 0;
}