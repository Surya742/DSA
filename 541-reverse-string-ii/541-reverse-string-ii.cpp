class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i <n; i++){
            int start = 1;
            int end = 2*k;
            string t = "";
            bool shld = true;
            while(start <= end && i < n){
                if(start <= end/2){
                    t.push_back(s[i]);
                }else if(shld){
                    reverse(t.begin(),t.end());
                    t.push_back(s[i]);
                    shld = false;
                }else{
                    t.push_back(s[i]);
                }
                start++;
                i++;
            }
            if(shld){
                reverse(t.begin(),t.end());
            }
            ans += t;
            i--;
        }
        return ans;
    }
};