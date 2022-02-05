// Minimum Cost to Set Cooking Time

// A generic microwave supports cooking times for:

// at least 1 second.
// at most 99 minutes and 99 seconds.
// To set the cooking time, you push at most four digits. The microwave normalizes 
// what you push as four digits by prepending zeroes. It interprets the first two 
// digits as the minutes and the last two digits as the seconds. It then adds them up as the cooking time. For example,

// You push 9 5 4 (three digits). It is normalized as 0954 and interpreted as 9 minutes and 54 seconds.
// You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 seconds.
// You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
// You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
// You are given integers startAt, moveCost, pushCost, and targetSeconds. Initially, 
// your finger is on the digit startAt. Moving the finger above any specific digit costs 
// moveCost units of fatigue. Pushing the digit below the finger once costs pushCost units of fatigue.

// There can be multiple ways to set the microwave to cook for targetSeconds seconds but you are interested in the way with the minimum cost.

// Return the minimum cost to set targetSeconds seconds of cooking time.

// Remember that one minute consists of 60 seconds.

// Prob link: https://leetcode.com/problems/minimum-cost-to-set-cooking-time/

class Solution {
public:
    int minCostSetTime(int sa, int mc, int pc, int t) {
        int ref = sa;
        int mini = t/60;
        int sec = t%60;
        int ans = INT_MAX;
        
        if(mini <= 99){
            mini = mini*100;
        }else{
            mini = (mini-1)*100;
            sec = 60+sec;
        }
        
        vector<int> v;
        v.push_back(mini+sec);
        
        if(sec+60 <= 99 && ((mini/100)-1 >= 0)){
            mini = ((mini/100)-1)*100;
            sec = sec+60;
            v.push_back(mini+sec);
        }
        
        for(auto it: v){
            vector<int> v2;
            int sum = 0;
            while(it>0){
                int x = it%10;
                it = it/10;
                v2.push_back(x);
            }
            reverse(v2.begin(), v2.end());
            for(auto xt: v2){
                if(sa == xt){
                    sum += pc;
                }else{
                    sum = sum + pc + mc;
                }
                sa = xt;
            }
            sa = ref;
            ans = min(ans, sum);
        }
        return ans;
    }
};