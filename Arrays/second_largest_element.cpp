#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondLargest(vector<int> nums, int size)
{
    if(size<2) return -1;
    
    int largest = INT_MIN;
    int sl = INT_MIN;
    for(int i=0; i<size; ++i)
    {
        if(nums[i] > largest){
            sl = largest;
            largest = nums[i];
        }
        else if(nums[i]>sl && nums[i]!=largest)
            sl = nums[i];
    }

    return sl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n,0);

    for(int i=0; i<n; ++i)
        cin >> nums[i];

    int result = secondLargest(nums,n);

    cout << "Second Largest element: " << result;

    return 0;
}