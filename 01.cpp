#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nmap;
        vector<int> ans(2);
        for (int i=0; i<nums.size(); i++) {
            int complement = target - nums[i];
            if (nmap.find(complement) != nmap.end()) {
                ans[0] = nmap[complement];
                ans[1] = i;
                return ans;
            }
            nmap[nums[i]] = i;
        }return ans;
    }
};