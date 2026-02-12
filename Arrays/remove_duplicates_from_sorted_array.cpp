//remove duplicates from sorted array, and make in-place change in the array such that the array must contain only all the unique elements

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
    vector<int> nums = {1,1,2};
    vector<int> expectedNums = {1,2};

    int k = removeDuplicates(nums); //k is the no. of unique elements

    for(int i=0; i<k; ++i)
    {
        if(nums[i]==expectedNums[i])
            continue;
        else 
        {
            cout << "Incorrect!!";
            return -1;
        }
    }
    return 0;
}


//My approach-2
//Changing the in-place elements by maintaining a variable j, and keeping the count using a variable k
//Update: No need of extra variables j and n.

int removeDuplicates(vector<int>& nums) {
    //int n = nums.size();
    //int j = 1;
    int k = 1;

    for(int i=1; i<nums.size(); ++i)
    {
        if(nums[i]!=nums[i-1])
        {
            nums[k] = nums[i];
            k++;
        }
        else
            continue;
    }

    return k;
}


//My approach-1
//Make a duplicate array and store unique elements in that array, then copy the duplicate array to the original array
// int removeDuplicates(vector<int>& nums)
// {
//     int n = nums.size();
//     vector<int> dup(n);

//     dup[0] = nums[0];
//     int k = 1;

//     for(int i=1; i<n; ++i)
//     {
//         if(nums[i-1]==nums[i])
//             continue;
//         else 
//             dup[k++] = nums[i];
//     }

//     for(int i=0; i<k; ++i)
//         nums[i] = dup[i];

//     return k;
// }