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
    int length(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }
    TreeNode* solve(ListNode* &head,int n){
        if(head==NULL || n<=0)return NULL;
        TreeNode* leftsubTree=solve(head,n/2);
        TreeNode* root=new TreeNode(head->val);
        head=head->next;
        root->left=leftsubTree;
        root->right=solve(head,n-n/2 -1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n=length(head);
        return solve(head,n);
    }
};