// Subarray Sum Equals K
// Prob link: https://leetcode.com/problems/subarray-sum-equals-k/

// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(mp[sum-k])
                ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};