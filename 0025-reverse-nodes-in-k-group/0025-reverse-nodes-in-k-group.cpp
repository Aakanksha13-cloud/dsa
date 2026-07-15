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
    int len(ListNode* head){
        int i=0;
        ListNode* temp=head;
        while(temp!=NULL){
            i++;
            temp=temp->next;
        }
        return i;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        int l=len(head);
        if(l<k)return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        int pos=0;
        while(pos<k && curr!=NULL){
            ListNode* right=curr->next;
            curr->next=prev;
            prev=curr;
            curr=right;
            pos++;
        }
        if(curr!=NULL){
            ListNode* rec=reverseKGroup(curr,k);
            head->next=rec;
        }
        return prev;
    }
};