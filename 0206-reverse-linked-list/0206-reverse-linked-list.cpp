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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {

            // Step 1: Save the next node
            next = curr->next;

            // Step 2: Reverse the link
            curr->next = prev;

            // Step 3: Move prev forward
            prev = curr;

            // Step 4: Move curr forward
            curr = next;
        }

        return prev; 
    }
};