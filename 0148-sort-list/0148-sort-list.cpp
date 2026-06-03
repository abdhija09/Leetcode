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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return NULL;
        vector<int>ans;
        ListNode* temp=head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* newhead=convertarr2ll(ans);
        return newhead;
    }
};