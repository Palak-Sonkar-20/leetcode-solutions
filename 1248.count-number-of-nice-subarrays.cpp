/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int oddCount = 0, result = 0;
        for (int num : nums) {
            if (num % 2 != 0) {
                oddCount++;
            }
            if (count.find(oddCount - k) != count.end()) {
                result += count[oddCount - k];
            }
            count[oddCount]++;
        } //explanation: The code uses a hash map to keep track of the count of odd numbers encountered so far. It iterates through the input array, updating the count of odd numbers and checking if there are any previous counts that would allow for a subarray with exactly k odd numbers. If such a count exists, it adds the number of those subarrays to the result. Finally, it returns the total count of nice subarrays found.
        //dry run: For example, given the input nums = [1, 1, 2, 1, 1] and k = 3, the code will iterate through the array and keep track of the odd counts. When it reaches the third odd number (the second '1' in the array), it will check if there are any previous counts that would allow for a subarray with exactly 3 odd numbers. It finds that there is one such count (the first '1'), so it adds that to the result. The final result will be 2, as there are two nice subarrays: [1, 1, 2] and [1, 2, 1].

        return result;
    }
};
// @lc code=end

