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
    TreeNode* ans = NULL;
    int solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return 0;
        }
        int left = solve(root->left,p,q);
        int right = solve(root->right,p,q);
        int self = 0;
        if(root==p || root==q){
            self = 1;
        }
        int total = left + right + self;
        if(total == 2 && ans == NULL){
            ans = root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};
