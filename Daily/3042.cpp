class Solution {
public:
    bool isPrefixAndSuffix(string& str1,string&  str2){
        if(str1.size() > str2.size()) return false;
    
        int i = 0;
        while(i < str1.size()) {
            if(str1[i] != str2[i]) return false;
            i++;
        }
    
        i = str1.size() - 1;
        int j = str2.size() - 1;
        while(i >= 0) {
            if(str1[i--] != str2[j--]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int result=0;
        int length  = words.size();
        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    result++;
                }
            }   
        }
        return result;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();