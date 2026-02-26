//look for a better approach
#include <bits/stdc++.h>
using namespace std;

vector<int> longestSubarray(vector<int> nums);
void show(vector<int> nums);
int main()
{
    vector<int> nums;
    vector<int> result;

    nums = {9,-3,3,-1,6,-5};
    show(nums);
    result = longestSubarray(nums);
    show(result);

    cout<<endl;
    
    nums = {6,-2,2,-8,1,7,4,-10};
    show(nums);
    result = longestSubarray(nums);
    show(result);

    return 0;
}

vector<int> longestSubarray(vector<int> nums)
{
    int mx=0,sum=0;
    int start=0,end=0;

    for(int i=0; i<nums.size(); ++i) {
        sum = 0;
        for(int j=i; j<nums.size(); ++j) {
            sum += nums[j];
            if(sum==0) {
                if(j-i+1>mx){
                    start = i;
                    end = j;
                    mx = j-i+1;
                }
            }
        }
    }

    vector<int> result(nums.begin()+start,nums.begin()+end+1);

    return result;
}

void show(vector<int> nums) {
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
}