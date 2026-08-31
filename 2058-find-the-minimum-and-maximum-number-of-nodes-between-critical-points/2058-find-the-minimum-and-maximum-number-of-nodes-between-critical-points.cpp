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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Edge Case: Agar list me 3 se kam nodes hain, toh critical point ban hi nahi sakta
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }

        int firstCP = -1; // Sabse pehla critical point track karne ke liye
        int prevCP = -1;  // Just pichla critical point track karne ke liye
        int minDist = INT_MAX; // Sabse choti distance store karne ke liye
        
        ListNode* prev = head;        // Piche wala node
        ListNode* curr = head->next;  // Current node jise check karna hai
        int idx = 1;                  // Index track karne ke liye (1-based indexing)

        // Loop tab tak chalega jab tak aakhri node tak na pahonch jaye
        while (curr->next != nullptr) {
            
            // Condition for Local Maxima or Local Minima
            bool isMaxima = (curr->val > prev->val) && (curr->val > curr->next->val);
            bool isMinima = (curr->val < prev->val) && (curr->val < curr->next->val);

            if (isMaxima || isMinima) {
                // Agar ye zindagi ka sabse pehla critical point hai
                if (firstCP == -1) {
                    firstCP = idx;
                } else {
                    // Agar pehle bhi CP mil chuke hain, toh minDist ko update karo
                    minDist = min(minDist, idx - prevCP);
                }
                // Current index ab agle critical point ke liye 'prevCP' ban jayega
                prevCP = idx;
            }

            // Pointers aur index ko aage badhao
            prev = curr;
            curr = curr->next;
            idx++;
        }

        // Agar firstCP aur prevCP same hain, matlab sirf 1 hi critical point mila (ya 0 mila)
        if (firstCP == prevCP) {
            return {-1, -1};
        }

        // Max distance hamesha last CP aur first CP ke beech ka difference hoga
        int maxDist = prevCP - firstCP;

        return {minDist, maxDist};
    }
};
