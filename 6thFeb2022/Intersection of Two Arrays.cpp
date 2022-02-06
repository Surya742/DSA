// Intersection of Two Arrays

// Given two integer arrays nums1 and nums2, 
// return an array of their intersection. 
// Each element in the result must be unique and you may return the result in any order.

// Prob Link: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        set<int> s1;
        set<int> s2;
        for(auto it: nums1){
            s1.insert(it);
        }
        for(auto it: nums2){
            s2.insert(it);
        }
        for(auto it: s1){
            mp[it]++;
        }
        for(auto it: s2){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it: mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};