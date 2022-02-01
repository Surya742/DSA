// Jump Game II
// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// You can assume that you can always reach the last index.

//Prob Link: https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int howfar = 0;
        int ans = 0;
        int curr = 0;
        for(int i = 0; i < nums.size()-1; i++){
            howfar = max(howfar, i+nums[i]);
            if(i == curr){
                curr = howfar;
                ans++;
            }
        }
        return ans;
    }
};