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
    int heightDia(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = heightDia(root->left);
        int right = heightDia(root->right);

        int ans = 1 + max(left,right);
        return ans;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftDia = diameterOfBinaryTree(root->left); // if diameter is only derived from the left subtree
        int rightDia = diameterOfBinaryTree(root->right); // if diameter is only derived from the right subtree
        int height =  heightDia(root->left) + heightDia(root->right); // if diameter is derived from the both subtrees(passes thru root node)

        int ans = max(leftDia,max(rightDia,height));
        return ans;
        
    }
};
