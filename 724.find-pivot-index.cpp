/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> Prefix(n+1, 0);
        for(int i=0;i<n;i++){
            Prefix[i+1] = Prefix[i]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(Prefix[i] == Prefix[n]-Prefix[i+1]){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

