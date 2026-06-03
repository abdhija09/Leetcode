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
ListNode* reversell(ListNode* head){
    ListNode* temp=head;
       ListNode* prev=NULL;
    while(temp){
      ListNode* front=temp->next;
      temp->next=prev;
      prev=temp;
      temp=front;
    }
  return prev;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(n==1){
    if(head == NULL) return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }
    ListNode* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
    }
    ListNode* headd=reversell(head);
    int cnt=0;
    ListNode* temp=headd;
    
    while(temp){
        cnt++;
        if(cnt==n-1){
            ListNode* k=temp->next;
            temp->next=temp->next->next;
            delete k;
            ListNode* newhead =reversell(headd);
            return newhead;
        }
        temp=temp->next;
    
    }
    reversell(headd);
    return headd;
    }
    
};