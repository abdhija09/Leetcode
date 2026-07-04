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

void convertlltoarr(ListNode* list,vector<int> &k){
    ListNode* temp=list;
    while(temp){
        k.push_back(temp->val);
        temp=temp->next;
    }
    return ;
   }
    vector<int>converttoarr(vector<ListNode*>& lists){
        int n=lists.size();
        vector<int>k;
        for(int i=0;i<n;i++){
            convertlltoarr(lists[i],k);
        }
    return k;
    }
    ListNode* convertarrtoll(vector<int> &k){
       if(k.empty()) return nullptr;
        ListNode* head= new ListNode(k[0]);
        ListNode* mover=head;
        for(int i=1;i<k.size();i++){
            ListNode* temp=new ListNode(k[i]);
            mover->next=temp;
            mover=temp;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>a =converttoarr(lists);
        sort(a.begin(),a.end());
        ListNode* newhead=convertarrtoll(a);
        return newhead;
    }
};