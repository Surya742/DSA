// Find Subsequence of Length K With the Largest Sum

// You are given an integer array nums and an integer k. 
// You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another 
// array by deleting some or no elements without changing the order of the remaining elements.

// Prob Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    
        vector<pair<int,int>> temp ;

        for(int i = 0 ; i < nums.size() ; i++){
            temp.push_back({nums[i] , i}) ;
        }

        sort(temp.begin() , temp.end()) ;

        vector<pair<int,int>> arr ;
        for(int i = nums.size() - k ; i < nums.size()  ; i++){
            arr.push_back({temp[i].second,temp[i].first}) ;
        }

        sort(arr.begin(),arr.end()) ;

        vector<int>  ans ;        
        for(int i = 0 ; i < k ; i++){
            ans.push_back(arr[i].second) ;
        }

        return ans ;
    }
};