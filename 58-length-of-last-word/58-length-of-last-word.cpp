class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        bool start = false;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] != ' '){
                start = true;
                cnt++;
                continue;
            }
            if(start && s[i] == ' '){
                break;
            }
        }
        return cnt;
    }
};