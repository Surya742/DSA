class Solution {
public:
    int titleToNumber(string c) {
        int ans = 0;
        for(int i = 0; i < c.length(); ++i){
            ans*=26;
            ans += (c[i] - 'A') + 1;
        }
        return ans;
    }
};