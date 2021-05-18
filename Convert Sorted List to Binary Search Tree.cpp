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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // convert to array and then convert to BST recursively
    TreeNode *convertToTree(TreeNode *root, vector<int> arr, int beg, int end)
    {
        if(beg > end)
            return NULL;
        
        int mid = beg + (end - beg) / 2;
        root = new TreeNode(arr[mid]);
        
        if(mid - 1 >= 0)
            root->left = convertToTree(root->left, arr, beg, mid - 1);
        if(mid + 1 < arr.size())
            root->right = convertToTree(root->right, arr, mid + 1, end);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        vector<int> arr;
        ListNode *temp = head;
        while(temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        TreeNode *resultRoot = NULL;
        
        return convertToTree(resultRoot, arr, 0, arr.size() - 1);
    }
};