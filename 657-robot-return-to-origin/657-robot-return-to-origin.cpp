class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, d = 0, l = 0, r = 0;
        for(auto ch: moves){
            if(ch == 'U'){
                u++;
                d--;
            }else if(ch == 'D'){
                d++;
                u--;
            }else if(ch == 'L'){
                l++;
                r--;
            }else if(ch == 'R'){
                r++;
                l--;
            }
        }
        if(!u && !d && !l && !r){
            return true;
        }
        return false;
    }
};