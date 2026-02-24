#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums);
void show(vector<int> nums);
void showResult(vector<vector<int>> result);

int main(){
    vector<int> nums;
    vector<vector<int>> result;

    nums = {-1,0,1,2,-1,4};
    show(nums);
    result = threeSum(nums);
    showResult(result);

    nums = {-1,0,1,0};
    show(nums);
    result = threeSum(nums);
    showResult(result);

    nums = {0,0,0,0};
    show(nums);
    result = threeSum(nums);
    showResult(result);

    return 0;
}

//Approach-1
vector<vector<int>> threeSum(vector<int> nums) {
    vector<int> temp;
    set<vector<int>> st;

    for(int i=0; i<nums.size()-2; ++i) {
        for(int j=i+1; j<nums.size()-1; ++j) {
            for(int k=j+1; k<nums.size(); ++k) {
                if(nums[i]+nums[j]+nums[k]==0) {
                    temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> result(st.begin(),st.end());

    return result;
}

//Approach-2
vector<vector<int>> threeSum(vector<int> nums) {
    int left, right;
    int sum = 0;
    vector<vector<int>> result;

    sort(nums.begin(),nums.end());
    for(int i=0; i<nums.size(); ++i) {
        if(i>0 && nums[i-1]==nums[i]) continue;

        left = i+1; right = nums.size()-1;
        while(left<right) {
            sum = nums[i] + nums[left] + nums[right];
            if(sum==0) {
                result.push_back({nums[i],nums[left],nums[right]});

                while(left<right && nums[left]==nums[left+1]) left++;
                while(left<right && nums[right]==nums[right-1]) right--;

                left++, right--;
            }
            else if(sum<0) 
                left++;
            else 
                right--;
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