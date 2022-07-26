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
     void solve(vector<int> ans,TreeNode* root,int k,int &count){
        if(root==NULL) return;
        ans.push_back(root->val);
        solve(ans,root->left,k,count);
        solve(ans,root->right,k,count);
        long long sum=0;
        for(int i=ans.size()-1;i>=0;i--){
            sum+=ans[i];
            if(sum==k)
                count++;
        }
            
        ans.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
          if(root==NULL) return 0;
        int count=0;
        vector<int> ans;
        solve(ans,root,targetSum,count);
        return count;
    }
};

