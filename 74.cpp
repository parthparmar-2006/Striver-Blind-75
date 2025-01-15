#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i: nums) mp[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int c=0;
        for (auto i: mp) {
            minHeap.push({i.second, i.first});
            c++;
            if (c>k) minHeap.pop(); 
        }
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        } return res;
    }
}; 