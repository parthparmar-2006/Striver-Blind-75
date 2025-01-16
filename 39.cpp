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
        return a.start < b.start;
    };
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size()<=1) return true;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i=0; i<intervals.size()-1; i++) {
            if (intervals[i+1].start<intervals[i].end) return false;
        } return true;
    } 
};
