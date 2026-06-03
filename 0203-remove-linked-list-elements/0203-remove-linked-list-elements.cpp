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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return head;
        ListNode*temp=head;
        ListNode* prev=nullptr;
        while(temp){
            if(head->val==val){
                head=head->next;
                  delete temp;
                  temp=head;
                continue;
            }
           if(temp->val==val && prev!=nullptr){
           ListNode* next=temp->next;
            prev->next=next;
           delete temp;
            temp=next;  
}
            else{
            prev=temp;
            temp=temp->next;}
        }
        return head;
    }
};