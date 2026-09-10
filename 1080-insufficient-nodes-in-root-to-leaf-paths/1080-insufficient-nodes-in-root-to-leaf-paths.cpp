/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // Base case: agar node NULL hai
        if (root == nullptr) {
            return nullptr;
        }
        
        // Base case 2: Agar ye LEAF node hai
        if (root->left == nullptr && root->right == nullptr) {
            // Check karo agar path sum limit se kam reh gaya
            if (root->val < limit) {
                return nullptr; // Delete node
            } else {
                return root;    // Keep node
            }
        }
        
        // Top-Down: Agar Left child hai, usko process karo 
        if (root->left != nullptr) {
            root->left = sufficientSubset(root->left, limit - root->val);
        }
        
        // Top-Down: Agar Right child hai, usko process karo
        if (root->right != nullptr) {
            root->right = sufficientSubset(root->right, limit - root->val);
        }
        
        // Bottom-Up Pruning: Process hone ke baad agar dono bacche ud chuke hain (ya pehle se NULL the)
        // iska matlab aage ka koi bhi raasta successful nahi raha.
        if (root->left == nullptr && root->right == nullptr) {
            return nullptr; // Is non-leaf (parent) node ko bhi udalo
        }
        
        // Agar ek bhi side ka raasta bacha hai, toh parent safe hai
        return root;
    }
};