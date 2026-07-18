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
    vector<int> lltoarr(ListNode* head){
        
        vector<int>ans;
        if(head==NULL) return ans;
        ListNode* temp= head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
     return ans;
    }
  ListNode* arrtoll(vector<int>& a){
    if(a.empty()) return NULL;

    ListNode* head = new ListNode(a[0]);
    ListNode* mover = head;

    for(int i = 1; i < a.size(); i++){
        mover->next = new ListNode(a[i]);
        mover = mover->next;
    }

    return head;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>a=lltoarr(list1);
        vector<int>b=lltoarr(list2);
        a.insert(a.end(), b.begin(), b.end());
        sort(a.begin(),a.end());
        ListNode* newhead=arrtoll(a);
        return newhead;
    }
};