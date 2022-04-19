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
    vector<int> sorted; //globally declared
    int i=0; //globally declared
    void doSort(TreeNode* root){
        if(!root){
            return;
        }
        doSort(root->left);
        sorted.push_back(root->val);
        doSort(root->right);
    }
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            dfs(root->left);
        }
        if(root->val==sorted[i]){
            i++;
        }
        else{
            root->val=sorted[i];
            i++;
        }
        if(root->right){
            dfs(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        doSort(root);
        sort(sorted.begin(), sorted.end());
        dfs(root);
    }
};