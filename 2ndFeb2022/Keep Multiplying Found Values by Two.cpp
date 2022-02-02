// Keep Multiplying Found Values by Two
// You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

// You then do the following steps:

// If original is found in nums, multiply it by two (i.e., set original = 2 * original).
// Otherwise, stop the process.
// Repeat this process with the new number as long as you keep finding the number.
// Return the final value of original.

// Prob Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        while(true){
            bool flg = true;
            for(auto it: nums){
                if(it == original){
                    original = 2*original;
                    flg = false;
                }
            }
            if(flg){
                break;
            }
        }
        return original;
    }
};