// Maximize Sum Of Array After K Negations

// Given an integer array nums and an integer k, modify the array in the following way:

// choose an index i and replace nums[i] with -nums[i].
// You should apply this process exactly k times. You may choose the same index i multiple times.

// Return the largest possible sum of the array after modifying it in this way.

// Prob Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(k==0){
                break;
            }
            else if(nums[i]<0){
                k--;
                nums[i]=-nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        while(k>0){
            nums[0]=-nums[0];
            k--;
        }
        for(auto i:nums){
            sum += i;
        }
        return sum;
    }
};