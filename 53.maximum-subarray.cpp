/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int max_sum = nums[0];
        for(int i = 0; i<n; i++){
            sum += nums[i];
            max_sum = max(max_sum, sum);
            if(sum < 0) sum = 0;
        }
        return max_sum;
    }
};
// @lc code=end

