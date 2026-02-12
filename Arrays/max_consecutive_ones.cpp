//find no. of maximum consecutive ones in the array
//arr[i] is either 0 or 1.
#include <bits/stdc++.h>
using namespace std;

//My Approach
int findMaxConsecutiveOnes(vector<int>& nums) {
    int mx = 0, count = 0;

    for(int i=0; i<nums.size(); ++i)
    {
        if(nums[i]==1)
            count++;
        else 
        {
            mx = max(count,mx);
            count = 0;
        }
    }

    mx = max(count,mx);

    return mx;
}

int main()
{
    vector<int> nums = {1,1,0,1,0,1,1,1};

    int result = findMaxConsecutiveOnes(nums);

    cout << result;

    return 0;
}