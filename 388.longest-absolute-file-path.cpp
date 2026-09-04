/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> levels;
        int max_length = 0;
        int current_length = 0;
        bool is_file = false;

        for (int i = 0; i <= input.length(); i++) {
            if (i < input.length() && input[i] != '\n' && input[i] != '\t') {
                current_length++;
                if (input[i] == '.') {
                    is_file = true;
                }
            } else {
                if (is_file) {
                    max_length = max(max_length, current_length);
                }
                current_length = 0;
                is_file = false;
            }
        }

        return max_length;
    }
};
// @lc code=end

