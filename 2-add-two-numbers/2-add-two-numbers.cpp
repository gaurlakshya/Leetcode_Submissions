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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d=new ListNode(0);
        ListNode*temp=d;
        int carry=0;
        int i=0,j=0;
        while(l1 || l2 || carry){
            int val1=0,val2=0;
            if(l1!=NULL){
                val1=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                val2=l2->val;
                l2=l2->next;
            }
            int ld=(carry+val1+val2)%10;
            carry=(carry+val1+val2)/10;
            ListNode* n=new ListNode(ld);
            temp->next=n;
            temp=n;
            if(l1==NULL && l2==NULL && carry!=0){
                ListNode* t=new ListNode(carry);
                temp->next=t;
                carry/=10;
            
            }
        }
        
        return d->next;
    }
};