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
        int left=height(root->left);
        int right=height(root->right);
        int maxi=max(left,right)+1;
        return maxi;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;

        }
        //left subtree
        int left=diameterOfBinaryTree(root->left);
        //right subtree
        int right=diameterOfBinaryTree(root->right);
        //doni milakr tree dekho 
        int both=height(root->left)+height(root->right);
        return max(left,max(right,both));


        
    }
};