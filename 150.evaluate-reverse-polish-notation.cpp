/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else result = a / b;

            s.push(result);
        }
        else {
            s.push(stoi(token)); 
        }
        }

        return s.top();
    }
};
// @lc code=end

