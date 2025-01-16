#include <bits/stdc++.h>
using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    static bool cmp(Interval a, Interval b) {
        return a.start==b.start? a.end<b.end: a.start<b.start;
    };
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size()<=1) return intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i=0; i<intervals.size(); i++) {
            if (minHeap.empty() || minHeap.top().first>intervals[i].start) {
                minHeap.push({intervals[i].end, 1});
            } else {
                auto ele = minHeap.top();
                minHeap.pop();
                minHeap.push({intervals[i].end, ele.second+1});
            }
        } 
        return minHeap.size();
    }
};