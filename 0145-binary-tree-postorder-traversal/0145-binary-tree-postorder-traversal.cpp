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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return {};
        }
        vector<int> leftTree=postorderTraversal(root->left);
        ans.insert(ans.end(),leftTree.begin(),leftTree.end());
        vector<int> rightTree=postorderTraversal(root->right);
        ans.insert(ans.end(),rightTree.begin(),rightTree.end());
        ans.push_back(root->val);

        return ans;
    }
};