// Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Prob Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        int mini = p[0];
        for(int i = 1; i < p.size(); i++){
            mini = min(mini,p[i]);
            ans = max(ans,p[i]-mini);
        }
        return ans;
    }
};