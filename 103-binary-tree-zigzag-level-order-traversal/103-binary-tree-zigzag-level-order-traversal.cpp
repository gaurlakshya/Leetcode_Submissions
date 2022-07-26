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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
        if(root==NULL) return res;
        bool lefttoright=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int siz=q.size();
            vector<int> ans(siz);
            for(int i=0;i<siz;i++){
                TreeNode* temp=q.front();
                q.pop();
                lefttoright?ans[i]=temp->val:ans[siz-i-1]=temp->val;
                 if(temp->left)
                     q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            res.push_back(ans);
            lefttoright=!lefttoright;
        }
        return res;
    }
};