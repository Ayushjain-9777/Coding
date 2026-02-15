//leader in an array is the element which is greater than all the elements to it's right
//rightmost element is always a leader.
#include <bits/stdc++.h>
using namespace std;

void leaders(vector<int>& nums);

int main()
{
    vector<int> nums;

    nums = {4,7,1,0};
    leaders(nums);

    nums = {10,22,12,3,0,6};
    leaders(nums);

    return 0;
}

void leaders(vector<int>& nums)
{
    int lead = nums[nums.size()-1];
    cout<<lead;
    for(int i=nums.size()-2; i>=0; --i)
    {
        if(nums[i]>lead)
        {
            lead = nums[i];
            cout<<" "<<lead;
        }
    }
}