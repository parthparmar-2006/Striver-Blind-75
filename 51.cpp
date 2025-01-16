#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxi = 0;
        int left = 0;
        for (int i=0; i<s.size(); i++) {
            if (mp[s[i]] == 0 || mp[s[i]] <= left) {
                mp[s[i]] = i+1;
            } else {
                maxi = max(maxi, i-left);
                left = mp[s[i]];
                mp[s[i]] = i+1;
            }
        } 
        // maxi = max(maxi, (s.size()-1-left));
        return maxi>(s.size()-1-left)? maxi: s.size()-left;
    }
};