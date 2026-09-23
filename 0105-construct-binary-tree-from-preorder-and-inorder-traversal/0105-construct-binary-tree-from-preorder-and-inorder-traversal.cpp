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
    void indexMap(unordered_map<int,int>&mp, vector<int>&inorder){

        int size = inorder.size();
        for(int i=0; i<size; i++){
            int ele = inorder[i];
            mp[ele] = i;
        }
        
    }

    TreeNode* solve(vector<int>& pre, vector<int>& ino, int start, int end, int &preIndex, unordered_map<int,int>&mp){
        // baase case
        if(start > end){
            return nullptr;
        }
        if(preIndex == ino.size()){
            return nullptr ;
        }
        int ele = pre[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(ele);
        int index=mp[ele];

        root->left = solve(pre, ino, start, index-1, preIndex, mp);
        root->right = solve(pre, ino, index+1, end, preIndex, mp);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>&inorder) {
        int start = 0;
        int end = inorder.size()-1;
        int preIndex = 0;
        //we need uss element ka index bhi too chaiye , taaki pta cle ki kiss index me h indorderme 
        unordered_map<int,int>mp;
        indexMap(mp, inorder);
        TreeNode* root=solve(preorder, inorder, start, end, preIndex, mp);
        return root;


        
        
        
    }
};