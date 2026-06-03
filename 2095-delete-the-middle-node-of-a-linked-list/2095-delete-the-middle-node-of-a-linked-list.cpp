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
int lenghtofll(ListNode* head){
    int cnt=0;
    ListNode* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
 return cnt;}
ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)return head;
        int n=lenghtofll(head);
        if(n==1){
         return nullptr;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            if(cnt==(n/2)&& temp->next){
                ListNode* k=temp->next;
                temp->next=temp->next->next;
                delete k;
                return head;
            }
            temp=temp->next;
        } 
        return head ; 
         }
};