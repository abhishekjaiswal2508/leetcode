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
    void insert(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        insert(root->left,ans);
        ans.push_back(root->val);
        insert(root->right,ans);
    }
    void update(TreeNode*& root, vector<int>& ans, int& index){
        if(root == NULL) return;
        update(root->left,ans,index);
        root->val = ans[index++];
        
        update(root->right,ans,index);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>ans;
        insert(root,ans);
        //update the value in ans
        int postsum=0;
        int i = ans.size()-1;
        while(i>=0){
            postsum += ans[i];
            ans[i] = postsum;
            i--;
        }
        int index = 0;
        update(root,ans,index);
        return root;




        
    }
};