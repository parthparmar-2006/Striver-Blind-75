#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i=0; i<=n; i++) {
            int cnt = 0;
            int num = i;
            while (num!=0) {
                cnt += (num&1);
                num >>= 1;
            } ans.push_back(cnt);
        } return ans;
    }
};