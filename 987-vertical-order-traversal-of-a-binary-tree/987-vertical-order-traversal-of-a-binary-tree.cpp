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
        vector<vector<int>> res;
        if(root==NULL) return res;
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode* ,pair<int,int>> p;
            p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int hd=p.second.first;
            int levl=p.second.second;
            mp[hd][levl].push_back(temp->val);
            if(temp->left)
                q.push(make_pair(temp->left,make_pair(hd-1,levl+1)));
            if(temp->right)
                q.push(make_pair(temp->right,make_pair(hd+1,levl+1)));
        }
        for(auto i:mp){
            vector<int> ans;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k:j.second)
                    ans.push_back(k);
            }
            res.push_back(ans);
        }
        return res;
    }
};