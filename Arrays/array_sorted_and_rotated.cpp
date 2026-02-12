#include <iostream>
#include <vector>
using namespace std;

//My approach
//If the array is sorted and rotated by x, then every element of original array(say arr[i]) should be arr[i] = nums[(i+x)%n]
bool isSorted(vector<int>& nums);

int main()
{
    int size;
    cin >> size;

    vector<int> nums(size);

    for(int i=0; i<size; ++i)
        cin >> nums[i];
    
    bool check = isSorted(nums);

    if(check==true)
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;

    return 0;
}


//Much better approach
bool isSorted(vector<int>& nums)
{
    int count = 0; //count stores the no. of violations in ascending order, if it's less than or equal to 1, then array is sorted
    int n = nums.size();

    for(int i=0; i<n-1; ++i)
    {
        if(nums[i]>nums[i-1])
            count++;
    }

    if(nums[n-1]>nums[0])   //checking if last element is greater than the first element or not 
        count++;

    return count<=1;
}

//My approach
//If the array is sorted and rotated by x, then every element of original array(say arr[i]) should be arr[i] = nums[(i+x)%n]
// bool isSorted(vector<int>& nums)
// {
//     int x = 0, n = nums.size();

//     for(int i=0; i<n-1; ++i)\
//     {
//         if(nums[i]>nums[i+1])
//         {
//             x = i+1;
//             break;
//         }
//         else {
//             continue;
//         }
//     }

//     vector<int> arr(n);

//     for(int i=0; i<n; ++i)
//     {
//         arr[i] = nums[(i+x)%n];
//     }

//     for(int i=0; i<n-1; ++i)
//     {
//         if(arr[i]>arr[i+1]) return false;
//     }

//     return true;
// }