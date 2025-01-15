#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = INT_MIN;
        for (int i=0; i<prices.size(); i++) {
            minPrice = min(prices[i], minPrice);
            maxProfit = max(prices[i]-minPrice, maxProfit);
        } return maxProfit;
    }
};