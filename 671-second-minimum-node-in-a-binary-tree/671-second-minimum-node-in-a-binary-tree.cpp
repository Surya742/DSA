class Solution {
public:

    set<int>ans;
void travesal(TreeNode*root)
{
    if(root==NULL)
        return ;
    travesal(root->left);
    ans.insert(root->val);
    travesal(root->right);
}
int findSecondMinimumValue(TreeNode* root) {
    travesal(root);
    vector<int>st(ans.begin(),ans.end());
    int n=st.size()-1;

    if(st.size()==1)
        return -1;
    else
    return st[1];
    
}
};