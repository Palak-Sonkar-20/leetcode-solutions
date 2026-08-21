/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            bool isDuplicate = false;
            while (curr->next && curr->val == curr->next->val) {
                isDuplicate = true;
                curr = curr->next;
            }
            if (isDuplicate) {
                prev->next = curr->next; // Skip all duplicates
            } else {
                prev = prev->next; // Move prev pointer
            }
            curr = curr->next; // Move to the next node
        }

        return dummy->next;
    }
};
// @lc code=end

