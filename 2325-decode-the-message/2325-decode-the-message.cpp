class Solution {
public:
    string decodeMessage(string key, string message) {
    key.erase(remove(key.begin(), key.end(), ' '), key.end());
    string ans;
     unordered_map<char,char>mpp;
     int count=0;
     for(int i=0;i<key.size();i++){
        if(mpp.count(key[i])){
              continue; 
        }
        else{
            mpp[key[i]]='a'+count;
            count++;           
        }
     }
     for(int i=0;i<message.size();i++){
        if(message[i]==' '){
            ans+=' ';         
        }
        else{
            ans+=mpp[message[i]];  
        }
     }
     return ans;
    }
};