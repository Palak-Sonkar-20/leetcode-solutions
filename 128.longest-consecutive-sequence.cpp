/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> Nset(nums.begin(), nums.end());
        int longestStreak = 0;
        for(int num : Nset){
            if(Nset.find(num - 1) == Nset.end()){
                int currentNum = num;
                int currentStreak = 1;

                while(Nset.find(currentNum + 1) != Nset.end()){
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;

        
    }
};
// @lc code=end

