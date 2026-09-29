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
    int solve(TreeNode* root, int& count){
        // base case
        if(!root) return 1;
        int leftans = solve(root->left,count);
        int rightans = solve(root->right,count);
        //update
        if(leftans == 0 || rightans == 0){
            count++;
            return 2;


        }
        if(leftans == 1 && rightans == 1){
            
            return 0;
        }
        //yha casse wesa jo ki , kisi me aagr 1 ya 2 waala typebn jaaye 
        return 1;
        

    }
    int minCameraCover(TreeNode* root) {
        int count = 0;
        //if(!root->left && !root->right) return 1 ;
        // count<<solve(root, count);
        int tem = solve(root, count);
        return tem?count:count + 1;
        
        
    }
};