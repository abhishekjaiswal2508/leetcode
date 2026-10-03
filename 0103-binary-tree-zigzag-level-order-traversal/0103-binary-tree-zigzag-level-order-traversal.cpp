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
    void solve(TreeNode* root, vector<vector<int>>&ans, int& count ){
        if(root == NULL) return ;
        queue<TreeNode*>q;
        q.push(root);
        ans.push_back({root->val});
        while(!q.empty()){
            vector<int>temp;
            int size = q.size();
            for(int i=0;i < size; i++){
                auto front = q.front();
                q.pop();
                if(front->right){
                    q.push(front->right);
                    temp.push_back(front->right->val);
                }
                if(front->left){
                    q.push(front->left);
                    temp.push_back(front->left->val);
                } 
            }
            if(temp.size() != 0){
                ans.push_back(temp);
                temp.clear();

            }
            
        }

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int count = 0;
        vector<vector<int>>ans;
        solve(root,ans,count);
        for(int i =0; i < ans.size(); i++){
            if(i % 2 == 0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;


        

        
    }
};