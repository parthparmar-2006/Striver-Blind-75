#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (int i: rows) {
            for (int k=0; k<matrix[0].size(); k++) {
                matrix[i][k] = 0;
            }
        }
        for (int i: cols) {
            for (int k=0; k<matrix.size(); k++) {
                matrix[k][i] = 0;
            }
        }
    }
};