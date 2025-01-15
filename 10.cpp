#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1;
        int maxArea = INT_MIN;
        while (i<j) {
            maxArea = max(maxArea, (min(height[i], height[j])*(j-i)));
            if (height[i]<height[j]) i++;
            else j--;
        } return maxArea;
    }
};