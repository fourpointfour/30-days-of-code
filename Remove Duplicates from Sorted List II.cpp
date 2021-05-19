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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode *temp = head, *newHead = NULL, *end;
        
        // initial count is zero, because it will turn 1 in the beginning
        // of the iteration of the linked list
        int currValue = temp->val, currCount = 0;
        while(temp != NULL)
        {
            if(temp->val == currValue)
                currCount++;
            else
            {
                if(currCount == 1)
                {
                    if(newHead == NULL)
                    {
                        newHead = new ListNode(currValue);
                        end = newHead;
                    }
                    else
                    {
                        end->next = new ListNode(currValue);
                        end = end->next;
                    }
                }
                
                currValue = temp->val;
                currCount = 1;
            }
            
            temp = temp->next;
        }
        
        if(currCount == 1)
        {
            if(newHead == NULL)
                newHead = new ListNode(currValue);
            else
                end->next = new ListNode(currValue);
        }
            
        return newHead;
    }
};