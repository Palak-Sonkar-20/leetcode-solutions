/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int curr =0;
       int next = curr+1;
       while(next<nums.size()){
           if(nums[curr]==0 && nums[next]!=0){
               swap(nums[curr],nums[next]);
               curr++;
               next++;
           }
           else if(nums[curr]==0 && nums[next]==0){
               next++;
           }
           else{
               curr++;
               next++;
           }
       }
        
    }
};
// @lc code=end

