/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
    vector<int> nums;
    unordered_map<int , int> mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        mp[val] = nums.size();
        nums.push_back(val);
        return true;
        
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int index = mp[val];
        mp[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

