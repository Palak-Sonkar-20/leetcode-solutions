/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int curmax = 0 , maxsum = nums[0];
        int curmin = 0 , minsum = nums[0];
        for(int it: nums){
            sum+= it;
            curmax = max(curmax + it, it);
            maxsum = max(maxsum, curmax);
            curmin = min(curmin + it, it);
            minsum = min(minsum, curmin);
        }
        if(sum == minsum) return maxsum;
        return max(maxsum, sum - minsum);
    }
};
// @lc code=end

