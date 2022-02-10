// K-diff Pairs in an Array

// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 0 <= i < j < nums.length
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

// Prob Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       set<int> s;
        unordered_map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(nums[i]-k)){
                s.insert(nums[i]-k);
            }
            if(mp.count(nums[i]+k)){
                s.insert(nums[i]);
            }
            mp[nums[i]]++;
        }
        return s.size();
    }
};