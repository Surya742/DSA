class Solution {
public:
    string reverseWords(string s) {
       int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++){
           string t = "";
            if(s[i] == ' '){
                ans.push_back(s[i]);
                continue;
            }
            while(i < n && s[i] != ' '){
                t.push_back(s[i]);
                i++;
            }
            reverse(t.begin(),t.end());
            ans += t;
            i--;
        }
        return ans;
    }
};