/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL||head->next==NULL)return head;
    struct ListNode* curr=head;
    struct ListNode* prev=NULL;
    while(curr!=NULL){
        struct ListNode* frwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=frwd;
    }
    return prev;
}