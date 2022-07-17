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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
          if(!root) return res;
               queue<TreeNode *>q;
        vector<int> vec;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *t=q.front();
            if(t!=NULL)
            vec.push_back(t->val);
            q.pop();
            if(t==NULL){
                res.push_back(vec);
                vec={};
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            
        }
        return res;
    }
};