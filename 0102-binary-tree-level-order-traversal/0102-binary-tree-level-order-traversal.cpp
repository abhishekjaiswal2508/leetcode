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
    void solve(TreeNode* root,vector<vector<int>>& ans){
        //base case
        queue<TreeNode*>q;
        if(root==NULL){
            return;
        }
        //initialise kr do que ko
        q.push(root);
        q.push(NULL);
        // vector<int>temp;
        vector<int>temp;
        while(!q.empty()){
            //front root nikalo 
            TreeNode* front=q.front();
            q.pop();
            
            if(front!=NULL){
                temp.push_back(front->val);
                if(front->left!=NULL){
                q.push(front->left);

                }
                if(front->right!=NULL){
                q.push(front->right);

                }
            }
            else{
                ans.push_back(temp);
                temp.clear();
                if(!q.empty()){
                q.push(NULL);

                }
            } 
            

        }
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        //level wise traversal krna h 
        //jisme queue ki help lgegi
        vector<vector<int>>ans;
        solve(root,ans);
        return ans;

        
    }
};