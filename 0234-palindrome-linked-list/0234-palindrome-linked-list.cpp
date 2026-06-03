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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return true;
        bool ok=true;
        vector<int>a;
        vector<int>b;
        ListNode* temp=head;
        while(temp){
            a.push_back(temp->val);
            b.push_back(temp->val);
            temp=temp->next;
        }
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
           if(a[i]!=b[i]){
            ok=false;
           }
        }
        return ok;
    }
};