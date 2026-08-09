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
class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        ListNode* tail=NULL;
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)pq.push(lists[i]);
        }
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            if(head==NULL && tail==NULL){
                head=t;
                tail=t;
            }
            else{
                tail->next=t;
                tail=t;
            }
            if(t->next!=NULL){
                pq.push(t->next);
            }
        }
        return head;
    }
};