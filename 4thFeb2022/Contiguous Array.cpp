// Contiguous Array
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
// Problem Link: https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> mp = {{0,-1}};
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] == 1 ? 1 : -1;
            if(mp.count(sum)){
                ans = max(ans, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};