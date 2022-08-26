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
    ListNode* swapPairs(ListNode* head) {
    ListNode *p=head,*q,*r=head;
    while(p&&p->next)
    {
        q=p->next;
        p->next=q->next;
        q->next=p;
        if(p==head)
        {
            head=q;
        }
        else{
            r->next=q;
        }
        r=p;
        p=p->next;
    }
    return head;
}
};