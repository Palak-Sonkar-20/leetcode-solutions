/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Check if there are at least k nodes left to reverse
            ListNode* kthNode = prevGroupEnd;
            for (int i = 0; i < k && kthNode; i++) {
                kthNode = kthNode->next;
            }
            if (!kthNode) break; // Not enough nodes to reverse

            // Reverse k nodes
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* curr = groupStart;
            ListNode* next = nullptr;
            ListNode* revPrev = nullptr;

            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = revPrev;
                revPrev = curr;
                curr = next;
            }

            // Connect the reversed part with the previous and next parts
            prevGroupEnd->next = revPrev; // New head of the reversed group
            groupStart->next = curr; // Connect the tail of the reversed group to the next part

            // Move prevGroupEnd to the end of the reversed group
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
// @lc code=end

