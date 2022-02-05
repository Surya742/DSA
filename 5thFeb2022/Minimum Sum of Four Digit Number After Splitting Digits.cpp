// Minimum Sum of Four Digit Number After Splitting Digits

// You are given a positive integer num consisting of exactly four digits. 
// Split num into two new integers new1 and new2 by using the digits found in num. 
// Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.

// For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. 
// Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
// Return the minimum possible sum of new1 and new2.

// Prob Link: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        while(num > 0){
            int x = num%10;
            num = num/10;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int a = 10*v[0] + v[3];
        int b = 10*v[1] + v[2];
        return a+b;
    }
};