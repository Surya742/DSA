// Add Digits

// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

// Prob Link: https://leetcode.com/problems/add-digits/

class Solution {
public:
    int addDigits(int num) {
        vector<int> v;
        int ans = 0;
        while(true){
            while(num > 0){
                int x = num%10;
                num = num/10;
                v.push_back(x);
            }
            int sum = 0;
            for(auto it: v){
                sum += it;
            }
            if(sum < 10){
                ans = sum;
                break;
            }else{
                num = sum;
                v.clear();
            }
        }
        return ans;
    }
};