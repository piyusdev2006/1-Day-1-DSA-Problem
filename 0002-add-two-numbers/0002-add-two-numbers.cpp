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
        // 1. Initialize a dummy head to easily anchor the result list
        ListNode dummy(0); 
        ListNode* curr = &dummy;
        int carry = 0;
        
        // 2. Loop until both lists are exhausted AND no carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Extract values, default to 0 if a list pointer hits nullptr
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate column total and separate digit from carry
            int total = val1 + val2 + carry;
            carry = total / 10;
            int digit = total % 10;
            
            // Allocate memory for the new node containing the digit
            curr->next = new ListNode(digit);
            
            // Move operational pointers forward
            curr = curr->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return dummy.next;
    }
};