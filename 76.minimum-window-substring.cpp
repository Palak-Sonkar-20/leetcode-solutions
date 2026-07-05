/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto c:t) mp[c]++;
        int left=0,right=0,count=t.size();
        int minlen = INT_MAX,start=0;
        while(right<s.length()){
            if(mp[s[right]]>0) count--;
            mp[s[right]]--;
            right++;
            while(count==0){
                if(right-left<minlen){
                    minlen = right-left;
                    start = left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0) count++;
                left++;
            }
        }
        if(minlen==INT_MAX) return "";
        else return s.substr(start,minlen);
    }
    };
// @lc code=end

