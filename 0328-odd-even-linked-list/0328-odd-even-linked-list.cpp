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
ListNode* convertarr2ll(vector<int>ans){
    ListNode* head=new ListNode(ans[0]);
    ListNode* mover=head;
    for(int i=1;i<ans.size();i++){
        ListNode* temp=new ListNode(ans[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL) return NULL;
       vector<int>ans;
       ListNode* temp=head;
       ListNode* prev=head;
        int cnt=0,count=0;
       while(temp){
        cnt++;
        if(cnt%2==1){
            ans.push_back(temp->val);
        }
        temp=temp->next;
       } 
       while(prev){
        count++;
        if(count%2==0){
            ans.push_back(prev->val);
        }
        prev=prev->next;
       } 
      ListNode* newhead= convertarr2ll(ans);
      return newhead;
    }
};