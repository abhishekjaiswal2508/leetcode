/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapping(TreeNode* root, unordered_map<TreeNode* , TreeNode*>&mp){
        if(!root) return;
        if(root->left){
            mp[root->left] = root;
            mapping(root->left, mp);
        }
        if(root->right){
            mp[root->right] = root;
            mapping(root->right, mp);
        }


    }

    void solve(TreeNode* root, TreeNode* target, int k, unordered_map<TreeNode* , TreeNode*>&mp, unordered_map<TreeNode* , bool>&visited, vector<int>&ans){
        if(!root) return ;
        int level=0;
        queue<TreeNode*> q;
        //initial 
        q.push(target);
        mp[root] = nullptr;
        visited[target] = true;

        while(!q.empty()){
            if( level == k){
                break;
            }
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                if(!visited[curr->left] && curr->left){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(!visited[curr->right] && curr->right){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(!visited[mp[curr]] && mp[curr]){
                    q.push(mp[curr]);
                    visited[mp[curr]] = true;
                }
                
            }
            level++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return;



    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //create the mapping for the node to its parents 
        unordered_map<TreeNode* , TreeNode*>mp;
        mapping(root, mp);
        unordered_map<TreeNode* , bool>visited;
        vector<int>ans;
        solve(root, target, k, mp, visited, ans);
        return ans;
        


        
    }
};