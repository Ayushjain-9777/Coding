#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>& nums);

int main()
{
    vector<int> result;
    
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; ++i)
        cin>>nums[i];
    result = majorityElement(nums);

    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<"\t";
    cout<<endl;

    return 0;
}

//Approach-1: Sort the array, and then check frequency for each element.
vector<int> majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int ele = nums[0];
    int n = nums.size();
    int freq = 0, idx = 0;
    vector<int> ans;

    for(int i=0; i<n; ++i) {
        if(nums[i]==ele) {
            freq++;
        } else {
            ele = nums[i];
            freq = 1;
        }
        if(freq>(n/3)) {
            if(idx>0 && ans[idx-1]==ele)
                continue;
            ans.push_back(ele);
            idx++;
        }
    }
    return ans;
}


// Approach-2: Boyer Moore Voting algorithm, for greater than n/3 occurences, an array can have atmost 2 majority element
vector<int> majorityElement(vector<int>& nums) {
    int ele1, ele2;
    int cnt1 = 0, cnt2 = 0;

    vector<int> result;
    
    for(int i=0; i<nums.size(); ++i) {
        if(cnt1==0 && nums[i]!=ele2) {
            ele1 = nums[i]; 
            cnt1 = 1;
        } else if(cnt2==0 && nums[i]!=ele1) {
            ele2 = nums[i]; 
            cnt2 = 1;
        }
        else if(nums[i]==ele1) cnt1++;
        else if(nums[i]==ele2) cnt2++;
        else {
            cnt1--; cnt2--;
        }
    }
    cnt1=0, cnt2=0;

    //checking the no of occurences
    for(int i=0; i<nums.size(); ++i) {
        if(nums[i]==ele1) cnt1++;
        if(nums[i]==ele2) cnt2++;
    }

    if(cnt1>nums.size()/3) result.push_back(ele1);
    if(cnt2>nums.size()/3) result.push_back(ele2);


    return result;
}