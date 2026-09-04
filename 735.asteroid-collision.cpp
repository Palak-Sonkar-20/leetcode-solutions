/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            if (st.empty() || asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        } 
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};
// @lc code=end

