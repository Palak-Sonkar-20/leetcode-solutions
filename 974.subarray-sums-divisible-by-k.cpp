/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            int mod = ((prefix[i] % k) + k) % k;
            if (mp.find(mod) != mp.end()) {
                ans += mp[mod];
            }
            mp[mod]++;
        }
        return ans;
    }
};
// @lc code=end

