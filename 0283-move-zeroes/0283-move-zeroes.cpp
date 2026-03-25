class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
                nums.erase(nums.begin()+i);
                i--;
            }
            else continue;
        }
        nums.insert(nums.end(),count,0);
        return;//void function donot return anything
    }
};