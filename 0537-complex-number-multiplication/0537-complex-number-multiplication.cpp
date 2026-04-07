class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        num1.erase(remove(num1.begin(), num1.end(), 'i'), num1.end());
        num2.erase(remove(num2.begin(), num2.end(), 'i'), num2.end());

        stringstream ss1(num1);
        string tokens1;
        vector<string> s1;

        stringstream ss2(num2);
        string tokens2;
        vector<string> s2;
        
        while(getline(ss1, tokens1, '+')){
            s1.push_back(tokens1);
        }
        while(getline(ss2, tokens2, '+')){
            s2.push_back(tokens2);
        }
       
        int a = stoi(s1[0]);
        int b = stoi(s1[1]);
        int c = stoi(s2[0]);
        int d = stoi(s2[1]);

        int n1 = a * c - b * d;
        int n2 = b * c + a * d;

        return to_string(n1) + "+" + to_string(n2) + "i";
    }
};