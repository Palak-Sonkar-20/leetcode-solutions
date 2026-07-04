/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int min1 = INT_MAX;
        int left = 0;
        for(int i = 0 ; i<n ; i++){
            sum += nums[i];
            
            while(sum >= target){
                min1 = min(min1, i-left+1); 
                sum-= nums[left];              
                left++;
            }        
                         
            
                      
        }
        return min1 == INT_MAX ? 0 : min1;
    }
};
// @lc code=end

