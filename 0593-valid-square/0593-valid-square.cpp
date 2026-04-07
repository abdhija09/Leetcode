class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        int d[6];

        d[0] = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        d[1] = (p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]);
        d[2] = (p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]);
        d[3] = (p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1]);
        d[4] = (p2[0]-p4[0])*(p2[0]-p4[0]) + (p2[1]-p4[1])*(p2[1]-p4[1]);
        d[5] = (p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1]);

        int mini = INT_MAX;
        int maxi=INT_MIN;
        for(int i = 0; i < 6; i++){
            if(d[i] >= 0){
                mini = min(mini, d[i]);
                maxi=max(maxi,d[i]);
            }
        }

        int count = 0;
        int ct=0;
        for(int i = 0; i < 6; i++){
            if(d[i] == mini){
                count++;
            }
            if(d[i] == maxi){
                ct++;
            }
        }
        bool ok = false;
        if(ct!=2){
            return ok;
        }
        if(count == 4){
        ok = true;
        return ok;
    }


        return ok;
    }
};