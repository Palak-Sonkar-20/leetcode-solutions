/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
        }

        return true;
    }
};
// @lc code=end

