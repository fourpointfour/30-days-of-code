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
    // maintain two different pointers for odd and even nodes
    // when both pointers reach at the end
    // just point the next of oddPtr towards the head of evenHead
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode *oddPtr = head, *evenPtr = head->next;
        ListNode *evenHead = evenPtr;
        
        while(oddPtr->next && evenPtr->next)
        {
            oddPtr->next = oddPtr->next->next;
            evenPtr->next = evenPtr->next->next;
            
            oddPtr = oddPtr->next;
            evenPtr = evenPtr->next;
        }
        
        oddPtr->next = evenHead;
        return head;
    }
};