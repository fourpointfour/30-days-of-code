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
    // we will use the two pointer approach
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        
        ListNode *first = head, *second = head;
        while(n-- && second != NULL)
            second = second->next;
        
        // if second ptr reaches the end then that means we have to remove the head node
        if(second == NULL)
        {
            head = head->next;
            return head;
        }
        
        while(second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};