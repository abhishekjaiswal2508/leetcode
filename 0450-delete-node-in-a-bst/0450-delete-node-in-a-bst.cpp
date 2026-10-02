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
    int getmax(TreeNode* root){
        // if(root == NULL) return NULL;
        while(root->right!= NULL){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* solve(TreeNode* root, int key){
        //base case 
        if(root == NULL){
            return NULL;
        }
        //aagr match kiya 
        if(root->val == key){
            //case 1
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
                

            }
            //case 2
            if(root->left != NULL && root->right == NULL){
                TreeNode* leftchild = root->left;
                root->left = NULL; //isolate kiya 
                delete root;
                return leftchild;
                

            }
            // case 3 
            if(root->left == NULL && root->right != NULL){
                TreeNode* rightchild = root->right;
                root->right = NULL; //isolate kiya 
                delete root;
                return rightchild;
                

            }//case 4 
            if(root->left != NULL && root->right != NULL){
                int maxi = getmax(root->left);
                root->val = maxi;
                root->left =  solve(root->left, maxi);

                

            }


        }
        else{
            if(key < root->val){
                root->left = solve(root->left,key);

            }
            else{
                root->right = solve(root->right,key);

            }

        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);



        
    }
};