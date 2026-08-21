/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        vector<pair<int , char>> freqVec;
        for(auto p : freq) {
            freqVec.push_back({p.second, p.first}); // Store frequency and character
        }

        sort(freqVec.begin(), freqVec.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first; // Sort by frequency in descending order
        });

        string result;
        for (auto p : freqVec) {
            result += string(p.first, p.second); // Append character p.first times
        }

        return result;
        
    }
};
// @lc code=end

