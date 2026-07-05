/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        while(right<n){
            if(nums[right]==0) k--;
            if(k<0){
                if(nums[left]==0) k++;
                left++;
            }
            right++;
        }
        return right - left;
    }
};
// @lc code=end

