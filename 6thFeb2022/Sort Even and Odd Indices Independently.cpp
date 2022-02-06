// Sort Even and Odd Indices Independently

// You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:

// Sort the values at odd indices of nums in non-increasing order.
// For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] 
// after. The values at odd indices 1 and 3 are sorted in non-increasing order.
// Sort the values at even indices of nums in non-decreasing order.
// For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] 
// after. The values at even indices 0 and 2 are sorted in non-decreasing order.
// Return the array formed after rearranging the values of nums.

// Prob Link: https://leetcode.com/problems/sort-even-and-odd-indices-independently/

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> evn;
        
        for(int i = 0; i < nums.size(); i++){
            if(i%2 == 0){
                evn.push_back(nums[i]);
            }else{
                odd.push_back(nums[i]);
            }
        }
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        sort(evn.begin(), evn.end());
        vector<int> ans;
        
        int oddi = 0;
        int evni = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(i%2 == 0){
                ans.push_back(evn[evni]);
                evni++;
            }else{
                ans.push_back(odd[oddi]);
                oddi++;
            }
        }
        return ans;
    }
};