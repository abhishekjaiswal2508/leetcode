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
    void indexMap(unordered_map<int,int>&mp, vector<int>&postorder){

        int size = postorder.size();
        for(int i=0; i<size; i++){
            int ele = postorder[i];
            mp[ele] = i;
        }
        
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int start, int end, int&posIndex, unordered_map<int,int>&mp){
        
        if(start > end){ // base case h inorder ka 
            return nullptr;
        }
        if(posIndex < 0 ){
            return nullptr;
        }
        int ele=postorder[posIndex];
        posIndex--;
        TreeNode* root = new TreeNode(ele);
        int index = mp[ele];
        
        root->right=solve(inorder, postorder, index + 1, end, posIndex, mp );
        root->left=solve(inorder, postorder, start, index -1, posIndex, mp );
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int start = 0;
        int end = inorder.size()-1;
        int posIndex = postorder.size() - 1;
        //we need uss element ka index bhi too chaiye , taaki pta cle ki kiss index me h indorderme 
        unordered_map<int,int>mp;
        indexMap(mp, inorder);
        TreeNode* root = solve(inorder, postorder, start, end, posIndex, mp);
        return root;
        
    }
};