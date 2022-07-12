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
class Solution {
ListNode* getMid(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* s=head;
    ListNode* f=head->next;
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        f=f->next->next;
    }
    return s;
    
}
    ListNode* reverse(ListNode* head){
        ListNode*curr=head;
        ListNode* prev=NULL;
        ListNode* nex=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* temp=getMid(head);
        ListNode* n=reverse(temp->next);
        temp->next=n;
        while(n!=NULL){
            if(head->val!=n->val){
                return false;
            }
            head=head->next;
            n=n->next;
        }
        return true;
    }
};