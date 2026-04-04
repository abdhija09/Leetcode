class Solution {
public:
    string frequencySort(string s) {
        int hash[128] = {0};
        string c = "";
        vector<int> x, y;

        for(int i = 0; i < s.size(); i++){
            hash[s[i]]++; 
        }

        for(int i = 0; i < 128; i++){
            if(hash[i] != 0){
                x.push_back(i);  
                y.push_back(hash[i]);
            }
        }
;
       
        vector<int> idx(x.size());
        iota(idx.begin(), idx.end(), 0); 
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return y[a] > y[b]; 
        });
        for(int i = 0; i < idx.size(); i++){
            c.insert(c.size(), y[idx[i]], x[idx[i]]); 
        }

        return c;
    }
};