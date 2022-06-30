/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode* s=head;
        ListNode* f=head;
        ListNode* n=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f)
                break;
        }
        if(f==NULL || f->next==NULL){
            return NULL;
        }else{
         f=head;
            while(n!=s){
                s=s->next;
                n=n->next;
            }
        }
        return s;
    }
};