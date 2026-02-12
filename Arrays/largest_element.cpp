#include <iostream>
#include <vector>
using namespace std;

int largest(vector<int> nums, int size)
{
    int largest = nums[0];
    for(int i=1; i<size; ++i)
    {
        if(nums[i] > largest)
            largest = nums[i];
    }

    return largest;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n,0);

    for(int i=0; i<n; ++i)
        cin >> nums[i];

    int result = largest(nums,n);

    cout << "Largest element: " << result;

    return 0;
}