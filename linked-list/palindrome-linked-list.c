/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next;

    while (curr != NULL) {
        next = curr->next;  // Save next node
        curr->next = prev;  // Reverse link
        prev = curr;        // Move prev forward
        curr = next;        // Move curr forward
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
     if (head == NULL || head->next == NULL) return true; 
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;
    struct ListNode* temp = secondHalf; 

    while (temp != NULL) {
        if (firstHalf->val != temp->val) {
            reverseList(secondHalf); 
            return false;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    reverseList(secondHalf);
    
    return true;
}