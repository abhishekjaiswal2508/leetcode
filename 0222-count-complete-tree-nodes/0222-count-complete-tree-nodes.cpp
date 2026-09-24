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
    int left(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        return count;
    }
    int right(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }
    int solve(TreeNode* root){
        int ans = 0;
        if(!root) return ans;
        int leftH = left(root);
        int rightH = right(root);
        if(leftH == rightH){
            return (1<<leftH) - 1;
        }
        else{
            int leftans = solve(root->left);
            int rightans = solve(root->right);
            return leftans + rightans + 1;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        
        return solve(root);
        
    }
};