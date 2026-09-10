/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int validNodesCount = 0; // final answer store karega

    // Helper function jo {Sum, Count} return karega
    pair<int, int> dfs(TreeNode* node) {
        // Base case: Agar node exist nahi karta
        if (node == nullptr) {
            return {0, 0};
        }

        // 1. Left subtree se data 
        pair<int, int> leftData = dfs(node->left);

        // 2. Right subtree se data 
        pair<int, int> rightData = dfs(node->right);

        // 3. Current node ka total Sum aur Count nikaalo
        int currentSum = leftData.first + rightData.first + node->val;
        int currentCount = leftData.second + rightData.second + 1;

        // 4. Condition check karo (Average == Node ki Value?)
        if (currentSum / currentCount == node->val) {
            validNodesCount++;
        }

        // 5. Parent node ke liye apna data bhej do
        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return validNodesCount;
    }
};