#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1, right=n-1;
            int target = 0-nums[i];
            while (left<right) {
                int sum = nums[left]+nums[right];
                if (sum==target) {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    sort(temp.begin(), temp.end());
                    res.push_back(temp);
                    int e1 = nums[left], e2 = nums[right];
                    while (left<right && nums[left]==e1) left++;
                    while (left<right && nums[right]==e2) right--;
                } else if (sum < target) {
                    left++;
                } else right--;
            }
        }
        return res;
    }
};