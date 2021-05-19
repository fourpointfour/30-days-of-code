/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // store the list nodes of first list
    // and while traversing the second, check if a list has been stored already
    // that stored node is the intersection point
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        set<ListNode*> st;
        ListNode *temp = headA;
        while(temp != NULL)
        {
            st.insert(temp);
            temp = temp->next;
        }
        
        temp = headB;
        while(temp != NULL)
        {
            if(st.find(temp) != st.end())
                return temp;
            
            temp = temp->next;
        }
        
        return NULL;
    }
};