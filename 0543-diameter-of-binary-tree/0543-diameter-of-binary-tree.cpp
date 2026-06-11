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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftH=height(root->left);
        int rightH=height(root->right);
        return max(leftH,rightH)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int currD=height(root->left)+height(root->right);
        int leftD=diameterOfBinaryTree(root->left);
        int rightD=diameterOfBinaryTree(root->right);
        
        return max(currD,max(leftD,rightD));
    }
};