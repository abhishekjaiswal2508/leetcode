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
    bool solve(TreeNode* root, int targetSum,int sum){
        //base case
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){// leafe node h thbhi check kro 
            
            return sum==targetSum;
        }
        
        bool left=solve(root->left,targetSum,sum);
        bool right=solve(root->right,targetSum,sum);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return solve(root,targetSum,sum);

        

        
    }
};