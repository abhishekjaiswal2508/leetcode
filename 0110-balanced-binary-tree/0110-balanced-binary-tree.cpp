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
    int hsolve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=hsolve(root->left);
        int right=hsolve(root->right);
        int height=max(left,right)+1;
        return height;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left=hsolve(root->left);
        int right=hsolve(root->right);
        int diff=abs(left-right);
        bool curr=false;
        if(diff<2){
            curr=true;    
        }
        bool leftans=isBalanced(root->left);
        bool rightans=isBalanced(root->right);
       if(curr && leftans && rightans){
        return true;
       }
       else{
        return false;
       }


        
    }
};