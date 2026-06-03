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
    ListNode* middleNode(ListNode* head) {
 
    ListNode* temp=head;
    int cnt=0;
    while(cnt<(lenghtofll(head)/2)){
        cnt++;
        temp=temp->next;
    }
    head=temp;

   return head;
    }
};