// Smallest Value of the Rearranged Number

// You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.

// Return the rearranged number with minimal value.

// Note that the sign of the number does not change after rearranging the digits.

// Prob Link: https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

class Solution {
public:
    long long smallestNumber(long long num) {
        long long ref = num;
        num = abs(num);
        if(num == 0) return 0;
        vector<int> dgt;
        vector<int> zro;
        
        while(num > 0){
            int x = num%10;
            num = num/10;
            if(x == 0){
                zro.push_back(x);
            }else{
                dgt.push_back(x);
            }
        }
        
        sort(dgt.begin(), dgt.end());
        long long ans = 0;
        
        if(ref > 0){
            for(int i = 0; i < dgt.size(); i++){
                ans = (ans*10) + dgt[i];
                if(i == 0){
                    for(auto it: zro){
                        ans = (ans*10);
                    }
                }
            }
        }else{
            for(int i = dgt.size()-1; i >= 0; i--){
                ans = (ans*10) + dgt[i];
            }
            for(auto it: zro){
                ans = (ans*10);
            }
        }
        if(ref < 0) ans = -ans;
        return ans;
    }
};