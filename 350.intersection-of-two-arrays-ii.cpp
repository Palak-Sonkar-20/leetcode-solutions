/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int ,  int> map1;
        vector<int> result;
        for( const auto & num : nums1){
            map1[num]++;
        }
        for( const auto & num : nums2){
            if(map1[num] > 0){
                result.push_back(num);
                map1[num]--;
            }
        }
        return result;
    }
};
// @lc code=end

