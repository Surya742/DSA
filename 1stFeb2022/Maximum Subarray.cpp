// Maximum Subarray

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

// Prob Link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kaden's Algoritm
        int max_end_here = 0;
        int max_so_far = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            max_end_here += nums[i];
            if(max_so_far < max_end_here){
                max_so_far = max_end_here;
            }
            if(max_end_here < 0){
                max_end_here = 0;
            }
        }
        return max_so_far;
    }
};