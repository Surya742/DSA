// Jump Game

// You are given an integer array nums. You are initially positioned at the array's 
// first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Prob link: https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int m=0,i;
        for( i=0;i<n;i++)
        {
            if(m<i)
                return false;
             m=max(nums[i]+i,m);
            
        }
            return true;
    }
};