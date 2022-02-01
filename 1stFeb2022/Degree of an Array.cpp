// Degree of an Array

// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

// Prob Link: https://leetcode.com/problems/degree-of-an-array/

class Solution {
public:
    int findShortestSubArray(vector<int>& arr) {
        map<int,int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        
        int mx = INT_MIN;
        for(auto it: mp){
            mx = max(mx, it.second);
        }
        vector<int> mxEle;
        for(auto it: mp){
            if(it.second == mx){
                mxEle.push_back(it.first);
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < mxEle.size(); i++){
            vector<int> temp;
            for(int j = 0; j < arr.size(); j++){
                if(arr[j] == mxEle[i]){
                    temp.push_back(j);
                }
            }
            ans = min(ans, temp[temp.size()-1] - temp[0] + 1);
        }
        return ans;
    }
};