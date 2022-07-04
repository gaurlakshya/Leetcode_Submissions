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
void find(vector<TreeNode*>&p1,TreeNode* root, TreeNode* t)
    {
        if(root==NULL)
            return;
        if(root->val == t->val)
        {
            p1.push_back(t);
            return;
        }
        else if(root->val>t->val)
        {
            p1.push_back(root);
            find(p1,root->left,t);
        }
        else
        {
            p1.push_back(root);
            find(p1,root->right,t);
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p1;
        vector<TreeNode*>p2;
        find(p1,root,p);
        find(p2,root,q);
        int a = 0;
        int b = 0;
        while(a<p1.size() && b<p2.size() && p1[a]->val==p2[b]->val)
        {
            a++;
            b++;
        }
        return p1[a-1];
    }
};