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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry=0;
        while(l1 && l2){
            int n = carry+ l1->val + l2->val;
            int digit = n%10;
            carry=n/10;
            if(head==NULL && tail == NULL){
                head = new ListNode(digit);
                tail = head;
            }
            else{
                tail->next= new ListNode(digit);
                tail=tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL ){
            int n = carry+ l1->val;
            int digit = n%10;
            carry=n/10;
            if(head==NULL && tail == NULL){
                head = new ListNode(digit);
                tail = head;
            }
            else{
                tail->next= new ListNode(digit);
                tail=tail->next;
            }
            l1 = l1->next;
        }
        while(l2 != NULL){
            int n = carry + l2->val;
            int digit = n%10;
            carry=n/10;
            if(head==NULL && tail == NULL){
                head = new ListNode(digit);
                tail = head;
            }
            else{
                tail->next= new ListNode(digit);
                tail=tail->next;
            }
            l2 = l2->next;
        }
        if(carry!=0) tail->next= new ListNode(carry);
        return head;
    }
};