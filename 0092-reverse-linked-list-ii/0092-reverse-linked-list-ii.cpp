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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        
        for(int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* next = NULL;

        ListNode* connection = prev;
        ListNode* tail = curr;

        // Reverse right-left+1 nodes
        for(int i = 0; i <= right - left; i++) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Reconnect
        connection->next = prev;
        tail->next = curr;

        return dummy->next;
    }
};