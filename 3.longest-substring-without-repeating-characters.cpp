/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window 
        unordered_set<char> set;
        int left = 0, right = 0, maxlength = 0;
        while(right< s.length()){
            if(set.find(s[right])==set.end()){
                set.insert(s[right]);
                maxlength = max(maxlength, right-left+1);
                right++;
            }
            else{
                set.erase(s[left]);
                left++;
            }
        }
        return maxlength;


        
    }
};
// @lc code=end

