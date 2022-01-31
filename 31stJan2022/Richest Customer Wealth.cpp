//1672. Richest Customer Wealth

// You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

// A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

class Solution {
public:
    int maximumWealth(vector<vector<int>>& v) {
        int ans = INT_MIN;
        for(int i = 0; i < v.size(); i++){
            int temp = 0;
            for(int j = 0; j < v[i].size(); j++){
                temp += v[i][j];
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/richest-customer-wealth/