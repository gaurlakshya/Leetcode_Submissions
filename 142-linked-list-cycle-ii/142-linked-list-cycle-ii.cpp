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
      if(head==NULL) return head; 
        ListNode * s=head;
        ListNode * f=head;
        while(f &&f->next){
            s=s->next;
            f=f->next->next;
            if(s==f) break;
        }
        if(f==NULL || f->next==NULL)
            return NULL;
        f=head;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};