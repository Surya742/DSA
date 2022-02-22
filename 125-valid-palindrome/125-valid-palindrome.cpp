class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for(char c: s){
            if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                newS.push_back(tolower(c));
            }
        }
        if(newS == "") return true;
        string ref = newS;
        reverse(ref.begin(),ref.end());
        if(ref == newS) return true;
        return false;
    }
};