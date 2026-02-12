#include <iostream>
#include <vector>
using namespace std;

//My Approach
void moveZeroes(vector<int>& nums) {
    int j = 0;

    for(int i=0; i<nums.size(); ++i)
    {
        if(nums[i]!=0)
        {
            nums[j++] = nums[i];
        }
    }

    for(int i=j; i<nums.size(); ++i)
    {
        nums[i] = 0;
    }
}

int main()
{
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);

    for(int i=0; i<nums.size(); ++i)
        cout << nums[i] << "\t";

    return 0;
}