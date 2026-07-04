/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int left = i+1;
            int right = nums.size()-1;
            
            while(left<right){
                int s = nums[left]+nums[right];
                if(s == target){
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(s<target) left++;
                else right--;
            }
        }
        return res;
    }
};
// @lc code=end

