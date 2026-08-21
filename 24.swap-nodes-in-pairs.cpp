/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr) {
            
            ListNode* first = curr;
            ListNode* second = curr->next;
            ListNode* nextPair = second->next;

            // Swap the nodes
            second->next = first;
            prev->next = second;
            first->next = nextPair;
            
            // Update head to the new first node
            prev = first;
            curr = nextPair;

            
        } 
        return dummy->next;
    }   
};

//
// @lc code=end

