class Solution {
public:
    int maxOperations(string s) {
        int count = 0;
        int operations = 0;
        
        for (int i=0;i<=s.size();i++) {
            if (s[i] == '1') {
                count++;
            }
            if (s[i] == '0') {
                if(i==s.size()-1){
                     operations+=count;
                }
                if(i<s.size()-1 && s[i+1]=='1'){
                     operations+=count;
                }
            }
        }
        
        return operations;
    }

};