// Sort Integers by The Number of 1 Bits

// You are given an integer array arr. 
// Sort the integers in the array in ascending order by the number of 1's 
// in their binary representation and in case of two or more integers have 
// the same number of 1's you have to sort them in ascending order.

// Return the array after sorting it.

// Prob link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<pair<int,int>> v;
        for(auto it: arr){
            int res = 0;
            int ref = it;
            while(it > 0){
                it = (it & (it-1));
                res++;
            }
            v.push_back({res, ref});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(auto it: v){
            ans.push_back(it.second);
        }
        return ans;
    }
};