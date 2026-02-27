#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> nums, int k);

int main()
{
    vector<int> nums; 
    int k;
    int result;

    nums = {4,2,2,6,4};
    k = 6;
    result = countSubarrays(nums,k);
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    cout<<"No. of subarrays: "<<result<<endl;
    cout<<endl;

    nums = {5,6,7,8,9};
    k = 5;
    result = countSubarrays(nums,k);
    for(int i=0; i<nums.size(); ++i) {
        cout<<nums[i]<<"\t";
    }
    cout<<endl;
    cout<<"No. of subarrays: "<<result<<endl;
    cout<<endl;

    return 0;
}

//Brute force Approach
int countSubarrays(vector<int> nums, int k) {
    int count = 0;
    int val = 0;


    for(int i=0; i<nums.size(); ++i) {
        val = 0;
        for(int j=i; j<nums.size(); ++j) {
            val ^= nums[j];
            if(val==k) count++;
        }
    }

    return count;
}

//Optmial Approach
int countSubarrays(vector<int> nums, int k) {
    int prefix = 0;
    unordered_map<int,int> freq;
    int count = 0;
    freq[0] = 1;

    for(int i=0; i<nums.size(); ++i) {
        prefix ^= nums[i];

        int target = prefix^k;

        if(freq.find(target)!=freq.end())
            count += freq[target];
        freq[prefix]++;
    }

    return count;
}