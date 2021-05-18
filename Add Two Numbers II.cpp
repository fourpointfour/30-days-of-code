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
    // store both lists into an array
    // traverse the array from the end
    // keep adding the result to the head of the result linked list
    
    ListNode* addInTheBeginning(int v, ListNode *head)
    {
        ListNode *temp = new ListNode(v, head);
        head = temp;
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        vector<int> list1, list2;
        ListNode *temp = l1;
        while(temp != NULL)
        {
            list1.push_back(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while(temp != NULL)
        {
            list2.push_back(temp->val);
            temp = temp->next;
        }
        
        ListNode *head;
        int carry = 0, i = list1.size() - 1, j = list2.size() - 1, sum;
        while(i >= 0 && j >= 0)
        {
            sum = list1[i] + list2[j] + carry;
            carry = sum / 10;
            if(head == NULL)
                head = new ListNode(sum % 10);
            else
                head = addInTheBeginning(sum % 10, head);
            --i;
            --j;
        }
        
        // adding boundary cases for the case if either of the list becomes
        // empty before the other
        while(i >= 0)
        {
            sum = list1[i] + carry;
            carry = sum / 10;
            
            head = addInTheBeginning(sum % 10, head);
            --i;
        }
        while(j >= 0)
        {
            sum = list2[j] + carry;
            carry = sum / 10;
            
            head = addInTheBeginning(sum % 10, head);
            --j;
        }
        
        // if there is still a carry left, we will add another node in the beginning of the list
        if(carry != 0)
            head = addInTheBeginning(carry, head);
        return head;
    }
};