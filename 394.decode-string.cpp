/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<string> s1;
        stack<int> s2;
        int num = 0;
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                s1.push(str);
                s2.push(num);
                str = "";
                num = 0;
            } else if (s[i] == ']') {
                int count = s2.top();
                s2.pop();
                string temp = s1.top();
                s1.pop();
                for (int j = 0; j < count; j++) {
                    temp += str;
                }
                str = temp; 
            } else {
                str += s[i];
            }
        }
        return str;
    }
};
// @lc code=end

