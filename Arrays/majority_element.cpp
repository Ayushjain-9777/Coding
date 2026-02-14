//Majority element is the element which occurs more than n/2 times in the array
//The array must has a element which has mr
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums);

int main()
{
    vector<int> nums;
    int major;

    nums = {3,2,3};
    major = majorityElement(nums);
    cout << major << endl;

    nums = {2,2,1,1,1,2,2};
    major = majorityElement(nums);
    cout << major << endl;

    return 0;
}

int majorityElement(vector<int>& nums) {
    int num = nums[0];
    int freq = 1;
    
    for(int i=1; i<nums.size(); ++i)
    {
        if(nums[i]==num)
            freq++;
        else 
            freq--;

        if(freq==0){
            num = nums[i];
            freq++;
        }
    }

    return num;
}