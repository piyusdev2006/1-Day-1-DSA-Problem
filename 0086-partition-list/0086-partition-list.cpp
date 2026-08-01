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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallDummy = new ListNode(0);
        ListNode* bigDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* big = bigDummy;

        while(head){

            if(head->val < x){

                small->next = head;
                small = small->next;
            }
            else{

                big->next = head;
                big = big->next;
            }

            head = head->next;
        }

        // End big list
        big->next = NULL;

        // Join both lists
        small->next = bigDummy->next;

        return smallDummy->next;
    }
};