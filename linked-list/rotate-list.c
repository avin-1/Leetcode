/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;  
    struct ListNode *p = head;
    int len = 1;
    while (p->next) {
        p = p->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    p->next = head;

    p = head;
    for (int i = 1; i < len - k; i++) {
        p = p->next;
    }
    head = p->next;
    p->next = NULL;

    return head;
}