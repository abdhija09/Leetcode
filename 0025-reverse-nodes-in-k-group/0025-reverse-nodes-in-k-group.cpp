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
int lenghtofll(ListNode* head){
    int cnt=0;
    ListNode* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
 return cnt;
 }
vector<int>convertll2arr(ListNode* head){
   vector<int>ans;
   int  n=lenghtofll(head);
   ListNode* temp=head;
   for(int i=0;i<n;i++){
    ans.push_back(temp->val);
    temp=temp->next;
   }
return ans;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>ans=convertll2arr(head);
       for(int i=0; i+k <= ans.size(); i+=k){
       reverse(ans.begin()+i, ans.begin()+i+k); 
}
        
        ListNode* newhead=convertarr2ll(ans);
        return newhead;
    }
};