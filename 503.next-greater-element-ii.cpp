/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n , -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) { 
            while (!st.empty() && nums[st.top()] <= nums[i % n]) { 
                st.pop();
            }
            if (i < n) {
                if (!st.empty()) {
                    res[i] = nums[st.top()];
                }
            }
            st.push(i % n);
        }
        return res;
        
    }
}; 
// @lc code=end

