/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        stack<int> s1, s2 , s3;
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry) {
            int sum = s1.empty() ? 0 : s1.top();
            if(!s1.empty()) s1.pop();
            sum += s2.empty() ? 0 : s2.top();
            if(!s2.empty()) s2.pop();
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            s3.push(sum);
        }
        ListNode* cur = dummy;
        while(!s3.empty()) {
            cur->next = new ListNode(s3.top());
            s3.pop();
            cur = cur->next;
        }
        return dummy->next;        
    }
};
// @lc code=end

