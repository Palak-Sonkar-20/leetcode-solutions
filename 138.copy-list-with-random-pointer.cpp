/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(0);
        Node* newCurr = newHead;
        Node* curr = head;
        unordered_map<Node*, Node*> map;

        // First pass: create copies of all nodes and store mapping
        while (curr != NULL) {
            map[curr] =  new Node(curr->val);
            curr = curr->next;
        }

        // Second pass: assign next and random pointers for the copied nodes
        curr = head;
        while (curr != NULL) {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }
};
// @lc code=end

