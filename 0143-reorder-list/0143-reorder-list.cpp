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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;

        // Find Middle
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){

            slow=slow->next;
            fast=fast->next->next;
        }

        // Split
        ListNode* second=slow->next;
        slow->next=NULL;

        // Reverse Second Half
        ListNode* prev=NULL;

        while(second){

            ListNode* next=second->next;

            second->next=prev;

            prev=second;

            second=next;
        }

        second=prev;

        // Merge
        ListNode* first=head;

        while(second){

            ListNode* temp1=first->next;
            ListNode* temp2=second->next;

            first->next=second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }
    }
};