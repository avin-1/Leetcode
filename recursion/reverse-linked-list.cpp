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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        struct ListNode *p,*q,*r;
        p = head; 
        q = head->next;
        r = NULL;
        while(q!=NULL){
            p->next = r;
            r = p;
            p = q;
            q = q->next;

        }
        p->next = r;
        head = p;
        return p;
    }
};