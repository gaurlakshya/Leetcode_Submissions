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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        q.push({root,{0,0}});;
        while(!q.empty()){
            pair<TreeNode* , pair<int,int>> p=q.front();
            q.pop();
            int hd=p.second.first;
            int lvl=p.second.second;
            TreeNode* node=p.first;
            
            mpp[hd][lvl].push_back(node->val);
            
            if(node->left)
                q.push({node->left,{hd-1,lvl+1}});
            if(node->right)
                q.push({node->right,{hd+1,lvl+1}});
        
        }
        
        for(auto j:mpp){
            vector<int> res;
           for(auto k:j.second){
               sort(k.second.begin(),k.second.end());
               for(auto t:k.second){
                   res.push_back(t);
               }
           }
            ans.push_back(res);
        }
        
        return ans;
    }
};