/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for (char c : num) {
            while (!result.empty() && k > 0 && result.back() > c) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }

        // If there are still digits to remove, remove from the end
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }

        result = result.substr(start);

        return result.empty() ? "0" : result;
        
    }
};
// @lc code=end

