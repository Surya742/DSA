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
private:
    void preorder(TreeNode* p, vector<int> &v){
        if(p == NULL){
            v.push_back(-10);
            return;
        }
        preorder(p->left,v);
        preorder(p->right,v);
        v.push_back(p->val);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1;
        preorder(p,v1);
        vector<int> v2;
        preorder(q,v2);
        return v1 == v2;
    }
};