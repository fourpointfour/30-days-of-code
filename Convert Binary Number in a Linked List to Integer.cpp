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
    // traverse the linked list to get all the values
    // then convert them to a decimal number
    int getDecimalValue(ListNode* head) {
        if(head == NULL)
            return 0;
        ListNode *temp = head;
        vector<int> nodes;
        while(temp != NULL)
        {
            nodes.push_back(temp->val);
            temp = temp->next;
        }
        
        int result = 0, power = 0;
        for(int i = nodes.size() - 1; i >= 0; --i)
        {
            result += pow(2, power) * nodes[i];
            power++;
        }
        return result;
    }
};