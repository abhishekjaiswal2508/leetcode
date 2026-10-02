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
    void solve(TreeNode* root,vector<int>& ans){
        if(root == NULL){
            return;
        }
        // queue<TreeNode* >q;
        // q.push(root);
        // while(!q.empty()){
            
        //     for(int i = 0; i < q.size(); i++){
        //         auto front = q.front();
        //         ans.push_back(front->val);
        //         q.pop();
        //         if(front->left){
        //             q.push(front->left);
        //         }
        //         if(front->right){
        //             q.push(front->right);
        //         }
        //     }
        // }
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right,ans);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        solve(root,ans);
        int s = 0;
        int e = ans.size() - 1;
        cout<<ans.size();
        while(s < e){
            int sum = ans[s] + ans[e];
            if(sum == k){
                return true;
            }
            if(sum > k){
                e--;
            }
            else{
                s++;
            }

        }
        return false;

        


        
        
    }
};