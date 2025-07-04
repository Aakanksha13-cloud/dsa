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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* temp=head;
        ListNode* prev =NULL;
        while(temp!=NULL && temp->next!=NULL){
            if(temp==head){
                head=temp->next;
                temp->next=head->next;
                head->next=temp;
            }
            else{
                prev->next=temp->next;
                prev=temp->next;
                temp->next=prev->next;
                prev->next=temp;
            }
            prev = temp;
            temp=temp->next;
        }
        return head;
    }
};