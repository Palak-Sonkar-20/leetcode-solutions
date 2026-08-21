/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0) {
                sum %= k;
            }
            if (mp.find(sum) != mp.end()) {
                if (i - mp[sum] > 1) {
                    return true;
                } 
            } else {
                mp[sum] = i;
            }
        }
        return false;
    } 
    // example: [23,2,4,6,7], k=6 
};
// @lc code=end

