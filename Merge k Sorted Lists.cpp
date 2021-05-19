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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        // n is the number of lists
        int n = lists.size();
        ListNode *ptr[n];
        for(int i = 0; i < n; ++i)
            ptr[i] = lists[i];
        // assigning the head of all the lists to the ptr array
        ListNode *head = NULL, *end;
        bool allNodesTraversed = false;
        while(!allNodesTraversed)
        {
            allNodesTraversed = true;
            int minValue = INT_MAX, minPtrIndex = -1;
            // if any node is encountered set the flag false;
            for(int i = 0; i < n; ++i)
            {
                if(ptr[i] != NULL)
                {
                    allNodesTraversed = false;
                    if(ptr[i]->val < minValue)
                    {
                        minValue = ptr[i]->val;
                        minPtrIndex = i;
                    }
                }
            }
            if(!allNodesTraversed)
            {
                if(head == NULL)
                {
                    head = new ListNode(minValue);
                    end = head;
                }
                else
                {
                    end->next = new ListNode(minValue);
                    end = end->next;
                }
                ptr[minPtrIndex] = ptr[minPtrIndex]->next;
            }
        }
        return head;
    }
};