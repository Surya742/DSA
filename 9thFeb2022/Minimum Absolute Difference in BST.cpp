// Minimum Absolute Difference in BST

// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

// Prob link; https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    void preorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return;
        }
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        preorder(root,v);
        int ans = INT_MAX;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v.size(); j++){
                if(i != j){
                    ans = min(ans, abs(v[i]-v[j]));
                }
            }
        }
        return ans;
    }
};