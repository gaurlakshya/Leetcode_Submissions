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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* s=head;
        ListNode* f=head->next;
        while(s!=f){
            s=s->next;
          
            if(f==NULL || f->next==NULL)
                return false;
              f=f->next->next;
        }
        return true;
    }
};