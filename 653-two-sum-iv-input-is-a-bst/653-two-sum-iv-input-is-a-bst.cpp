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
     void solve(TreeNode* root, vector<int> & ans){
       if(root==NULL) return ;
       solve(root->left,ans);
       ans.push_back(root->val);
       solve(root->right,ans);
   }
    bool findTarget(TreeNode* root, int target) {
        vector<int> ans;
    solve(root,ans);
    int s=0,e=ans.size()-1;
    while(s<e){
        if(ans[s]+ans[e]==target)
        return true;
        else if(ans[s]+ans[e]>target)
        e--;
        else
        s++;
    }
    return false;
    }
};