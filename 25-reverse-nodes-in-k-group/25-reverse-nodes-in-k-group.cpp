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
   int length(ListNode* head) {
    int len = 0;
    while(head) {
        head = head->next;
        len++;
    }
    return len;
}

ListNode* reverseList(ListNode* head, int k, ListNode* &temp) {
    ListNode *prev = NULL, *store;
    temp = head;
    while(temp && k--) {
        store = temp->next;
        temp->next = prev;
        prev = temp;
        head = temp;
        temp = store;
    }
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    int len = length(head);
    if(len < k) {
        return head;
    }
    ListNode *newHead = NULL, *tail = head, *temp = NULL; 
    newHead = reverseList(head, k, temp);
    len -= k;
    
    while(temp) {
        ListNode *t = temp, *Ttail = temp;
        temp = NULL;
        if(len - k < 0) {
            tail->next = t;
            return newHead;
        }
        tail->next = reverseList(t, k, temp);
        tail = Ttail;
        len -= k;
    }
    
    return newHead;
}
};