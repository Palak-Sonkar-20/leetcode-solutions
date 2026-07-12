/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin() , piles.end());
        while(left< right){
            int mid = left + (right - left) / 2;
            long long hours = 0;
            for(int pile : piles){
                hours += (pile + mid - 1) / mid;
            }
            if(hours > h){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

