#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target);
void show(vector<int> nums);
void showResult(vector<vector<int>> result);

int main(){
    vector<int> nums;
    int target;
    vector<vector<int>> result;

    nums = {-1,0,1,2,-2,0};
    target = 0;
    show(nums);
    result = fourSum(nums,target);
    showResult(result);

    nums = {2,2,2,2,2};
    target = 8;
    show(nums);
    result = fourSum(nums,target);
    showResult(result);

    nums = {4,3,3,4,4,2,1,2,1,1};
    target = 9;
    show(nums);
    result = fourSum(nums,target);
    showResult(result);

    return 0;
}

//Approach-1
vector<vector<int>> fourSum(vector<int> nums, int target) {
    set<vector<int>> st;
    vector<int> temp;
    long long sum;

    for(int i=0; i<nums.size()-3; ++i) {
        for(int j=i+1; j<nums.size()-2; ++j) {
            for(int k=j+1; k<nums.size()-1; ++k) {
                for(int l=k+1; l<nums.size(); ++l) {
                    sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target) {
                        temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> result(st.begin(),st.end());

    return result;
}

//Approach 2
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int left, right;
    vector<vector<int>> result;
    long long sum;

    sort(nums.begin(),nums.end());

    for(int i=0; i<nums.size(); ++i) {
        if(i>0 && nums[i]==nums[i-1])
            continue;
        for(int j=i+1; j<nums.size(); ++j) {
            if(j>i+1 && nums[j]==nums[j-1]) continue;

            left = j+1; right = nums.size()-1;
            
            while(left<right) {
                sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];

                if(sum==target) {
                    vector<int> temp = {nums[i],nums[j],nums[left],nums[right]};
                    result.push_back(temp);

                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++, right--;
                }
                else if(sum<target) left++;
                else right--;
            }
        }
    }

    return result;
}

void show(vector<int> nums) {
    for(int i=0; i<nums.size(); ++i) {
        cout << nums[i] << "\t";
    }
    cout<<endl;
}

void showResult(vector<vector<int>> result) {
    for(int i=0; i<result.size(); ++i) {
        for(int j=0; j<result[i].size(); ++j) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}