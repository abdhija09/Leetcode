class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>mpp; 
        ListNode* mov = head;
        ListNode* prev = NULL;
        while(mov){
            if(mpp[mov->val]==1){
                if(prev == NULL){
                    head = mov->next;
                    delete mov;
                    mov = head;
                }
                else{
                    prev->next = mov->next;
                    delete mov;
                    mov = prev->next;
                }
            }
            else{
                mpp[mov->val]++;
                prev = mov;
                mov = mov->next; 
            }
        }  
        return head;
    }
};