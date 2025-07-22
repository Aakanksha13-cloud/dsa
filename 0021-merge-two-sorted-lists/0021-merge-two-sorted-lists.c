/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1==NULL)return list2;
    if(list2==NULL)return list1;
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val=0;
    temp->next=NULL;
    struct ListNode* p = temp;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            p->next=list1;
            p=list1;
            list1=list1->next;
        }
        else{
            p->next=list2;
            p=list2;
            list2=list2->next;
        }
    }
    if(list1!=NULL)p->next=list1;
    if(list2!=NULL)p->next=list2;
    return temp->next;
}