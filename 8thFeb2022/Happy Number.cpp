// Happy Number

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Prob Link: https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        if(n == 0) return false;
        unordered_map<int,bool> mp;
        while(true){
            vector<int> v;
            while(n > 0){
                int x = n%10;
                n = n/10;
                v.push_back(x);
            }
            int sum = 0;
            for(auto it: v){
                sum += it*it;
            }
            if(mp[sum]){
                return false;
            }
            if(sum == 1){
                return true;
            }else{
                mp[sum] = true;
                n = sum;
            }
        }
        return false;
    }
};