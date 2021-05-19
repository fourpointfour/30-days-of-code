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
    // time efficient solution, not memory efficient
    // there will be N / k elements in one part
    // and the initial N % k parts will contain one extra element each
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // if(root == NULL)
        //     return vector<ListNode*>();
        
        // copying the list into array
        vector<int> arr;
        ListNode *temp = root;
        while(temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int N = arr.size();
        
        int elementCountInParts = N / k, extraCount = N % k;
        // extraCount gives us the number of lists in the beginning that will
        // have one element extra
        int listCount = 0, i = 0;
        vector<ListNode*> res;
        while(i < N)
        {
            ListNode *head = NULL, *end;
            listCount++;
            int eleCount = 0;
            while(eleCount < elementCountInParts && i < N)
            {
                if(head == NULL)
                {
                    head = new ListNode(arr[i++]);
                    end = head;
                }
                else
                {
                    end->next = new ListNode(arr[i++]);
                    end = end->next;
                }
                eleCount++;
            }
            if(listCount <= extraCount)
            {
                if(head == NULL)
                {
                    head = new ListNode(arr[i++]);
                    end = head;
                }
                else
                {
                    end->next = new ListNode(arr[i++]);
                    end = end->next;
                }
                eleCount++;
            }
            res.push_back(head);
        }
        while(listCount < k)
        {
            res.push_back(NULL);
            listCount++;
        }
        return res;
    }
};