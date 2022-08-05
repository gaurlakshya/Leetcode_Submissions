/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* create(int s,int e,vector<int> &ans){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        root->left=create(s,mid-1,ans);
        root->right=create(mid+1,e,ans);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ans;
        if(head==NULL) return NULL;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
    TreeNode* n=create(0,ans.size()-1,ans);
        return n;
    }
};