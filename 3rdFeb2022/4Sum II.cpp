// 4Sum II
// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for(auto c : nums3){
            for(auto d : nums4){
                mp[c+d]++;
            }
        }
        int count=0;
        for(auto a : nums1){
            for(auto b : nums2){
                if(mp.find(-(a+b)) != mp.end()){
                    count+=mp[-(a+b)];
                }
            }
        }
        return count;
    }
};