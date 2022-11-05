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
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode * temp=new ListNode(1);
        ListNode* ans=temp;
        int carry=0;
        
        while(l1 || l2 || carry){
            long long int sum=0;
            if(l1)
                sum+=l1->val;
            if(l2) sum+=l2->val;
            sum+=carry;
            int ld=sum%10;
            temp->next=new ListNode(ld);
            temp=temp->next;
            carry=sum/10;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        return ans->next;
    }
};