// Get Maximum in Generated Array
// You are given an integer n. A 0-indexed integer array nums of length n + 1 is generated in the following way:

// nums[0] = 0
// nums[1] = 1
// nums[2 * i] = nums[i] when 2 <= 2 * i <= n
// nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
// Return the maximum integer in the array nums​​​.

// Problem Link: https://leetcode.com/problems/get-maximum-in-generated-array/

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> arr;
        for(int i = 0; i < n+1; i++){
            arr.push_back(0);
        }
        for(int i = 0; i < n+1; i++){
            if(i == 0 || i == 1){
                arr[i] = i;
            }
            
            if((2 * i <= n) && (2 <= 2 * i)){
                arr[2 * i] = arr[i];
            }
            
            if((2 * i + 1 <= n) && (2 <= 2 * i + 1)){
                arr[2 * i + 1] = arr[i] + arr[i + 1];
            }
        }
        int ans = INT_MIN;
        for(auto it: arr){
            ans = max(ans, it);
        }
        return ans;
    }
};