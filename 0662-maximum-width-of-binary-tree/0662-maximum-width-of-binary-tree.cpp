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
    int  solve(TreeNode* root){
        unsigned long long maxi=0;
        if(!root) return maxi;
        queue<pair<TreeNode* , int>>q;
        //intial 
        q.push({root,1});

        while(!q.empty()){

            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            unsigned long long width = right - left + 1;
            maxi=max(maxi, width);
            unsigned long long size = q.size();

            for(int i =0; i < size; i++){
                auto curr = q.front();
                TreeNode* node = curr.first;
                unsigned long long index = curr.second;
                q.pop();
                if(node->left){
                    q.push({node->left, 2*index });
                }
                if(node->right){
                    q.push({node->right, 2*index + 1 });
                }


            }


        }
        return maxi;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return solve(root);

        
        
    }
};