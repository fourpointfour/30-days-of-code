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
    // we will use two pointer approach to find the k-th from the end
    // but before that, we will store the reference to k-th from the beginning
    // in another pointere so that we can swap the values easily later
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head, *second = head;
        
        for(int i = 0; i < k - 1; ++i)
        {
            second = second->next;
        }
        ListNode *beg = second;
        while(second && second->next)
        {
            first = first->next;
            second = second->next;
        }
        
        // now swap the value of beg and first
        int temp = beg->val;
        beg->val = first->val;
        first->val = temp;
        
        return head;
    }
};