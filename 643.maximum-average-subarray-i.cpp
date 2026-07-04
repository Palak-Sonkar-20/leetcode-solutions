/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxavg = INT_MIN;

        double sum = 0;
        for(int j=0;j<k;j++){
            sum+=nums[j];
        }
        maxavg = max(maxavg, sum/k);
        for(int i=k;i<n;i++){
            sum+=nums[i]-nums[i-k];
            maxavg = max(maxavg, sum/k);
            
        }
        return maxavg;
    }
};
// @lc code=end

