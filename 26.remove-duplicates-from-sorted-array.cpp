/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int curr = 0;
        for(int next=1;next<nums.size();next++){
            if(nums[curr]!=nums[next]){
                curr++;
                nums[curr]=nums[next];
            }
        }
        return curr+1;
    }
};
// @lc code=end

