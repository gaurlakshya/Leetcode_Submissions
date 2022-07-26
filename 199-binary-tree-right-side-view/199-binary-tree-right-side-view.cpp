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
    vector<int> rightSideView(TreeNode* root) {
          vector<int> ans;
   if(root==NULL) return ans;
   map<int,int> mp;
   queue<pair<TreeNode*,int>> q;
   q.push({root,0});
   while(!q.empty()){
       pair<TreeNode*,int> p=q.front();
       q.pop();
       TreeNode* node=p.first;
       int levl=p.second;
       //if(!mp[levl]){
           mp[levl]=node->val;
       //}
       if(node->left)
            q.push({node->left,levl+1});
        if(node->right)
            q.push({node->right,levl+1});
   }
   for(auto x:mp)
            ans.push_back(x.second);
            return ans;
        
    }
};