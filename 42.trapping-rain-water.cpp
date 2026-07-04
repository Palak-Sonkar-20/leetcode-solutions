/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int volume = 0;
        for(int i = 0; i < height.size(); i++) {
            while(!st.empty() && height[i] > height[st.top()]){
                int top = st.top();
                st.pop();
                if(st.empty()) break;
                int distance = i - st.top()-1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                volume += distance * bounded_height;
            }
            st.push(i);
        }
        return volume;
    }
};
// @lc code=end

