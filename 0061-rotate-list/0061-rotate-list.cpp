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
 ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next || k==0) return head;
    int n=0;
    ListNode* t=head;
    while(t){ n++; t=t->next; }
    k=k%n;   
    int cnt=0;
    while(cnt<k){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp->next){
            prev=temp;
            temp=temp->next;
        }
        int carry=temp->val;
        ListNode* t=head;
        while(t){
            int tmp=t->val;
            t->val=carry;
            carry=tmp;
            t=t->next;
        }
        cnt++;
    }
    return head;
}
};