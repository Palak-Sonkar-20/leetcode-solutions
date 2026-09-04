/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long result = 0;
        long long num = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            else if (s[i] == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }

            else if (s[i] == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }

            else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (s[i] == ')') {
                result += sign * num;
                num = 0;

                int oldSign = st.top();
                st.pop();

                int oldResult = st.top();
                st.pop();

                result = oldResult + oldSign * result;
            }
        }

        result += sign * num;
        return result;
    }
};
// @lc code=end

