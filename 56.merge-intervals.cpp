/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if( intervals.empty()) return {};
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for( auto interval : intervals){
            if( res.back()[1] >= interval[0]){
                res.back()[1] = max(res.back()[1], interval[1]);
            } else {
                res.push_back(interval);
            }
        }
        return res;
    }
};
// @lc code=end

