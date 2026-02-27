//check for more optimal solutions
#include <bits/stdc++.h>
using namespace std;

vector<int> repeatingAndMissing(vector<int> nums);
void show(vector<int> nums);

int main()
{
    vector<int> nums;
    vector<int> result;

    nums = {3,5,4,1,1};
    show(nums);
    result = repeatingAndMissing(nums);
    cout<<"Repeating number: "<<result[0]<<", Missing number: "<<result[1]<<endl;
    cout<<endl;

    nums = {1,2,3,6,7,5,7};
    show(nums);
    result = repeatingAndMissing(nums);
    cout<<"Repeating number: "<<result[0]<<", Missing number: "<<result[1]<<endl;
    cout<<endl;

    return 0;
}

//Approach-1
vector<int> repeatingAndMissing(vector<int> nums)
{
    int repeating=0, missing=1;
    vector<int> result(2);

    sort(nums.begin(),nums.end());

    int target = (nums.size()*nums.size()+1)/2;
    int sum = 0;
    for(int i=0; i<nums.size(); ++i) {
        if(i>0 && nums[i-1]==nums[i]) {
            result[repeating] = nums[i];
            continue;
        }
        sum += nums[i];
    }

    result[missing] = target - sum;

    return result;
}

//Approach-2
vector<int> repeatingAndMissing(vector<int> nums)
{
    vector<int> result(2,-1);
    vector<int> freq(nums.size(),0);

    for(int i=0; i<nums.size(); ++i) {
        freq[nums[i]-1]++;
    }
    for(int i=0; i<freq.size(); ++i) {
        if(freq[i]==2)
            result[0] = i+1;
        if(freq[i]==0)
            result[1] = i+1;
    }

    return result;
}

void show(vector<int> nums)
{
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
}