class Solution {
public:
    bool isHappy(int n) {
        bool ok = false;
        int sq = 0;
        vector<int> a; 
        set<int> seen; 

        while(!ok){
            sq = 0;     
            a.clear();   

            while(n > 0){
                int digit = n % 10;
                a.push_back(digit);
                n /= 10;
            }

            for(int i = 0; i < a.size(); i++){
                sq += a[i] * a[i];
            }

            if(sq == 1){
                ok = true;
                break;
            }

            if(seen.count(sq)) break;
            seen.insert(sq);

            n = sq;
        }    
        return ok;
    }
};