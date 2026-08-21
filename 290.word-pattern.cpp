/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        istringstream iss(s);
        string word;
        int i = 0;
        while (iss >> word) {
            if (i >= pattern.size()) return false;
            char c = pattern[i];
            if (mp.count(c) && mp[c] != word) return false;
            if (mp2.count(word) && mp2[word] != c) return false;
            mp[c] = word;
            mp2[word] = c;
            i++;
        }
        return i == pattern.size(); 
    } 
};
// @lc code=end

