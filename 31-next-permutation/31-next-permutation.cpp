class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int idx = -1;
        for(int i = size-1; i > 0; i--){
            if(nums[i]>nums[i-1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            sort(nums.begin(), nums.end());
        }else{
           int prev = idx;
            for(int i = idx+1; i < size; i++){
                if(nums[i] <= nums[prev] && nums[i] > nums[idx-1]){
                    prev = i;
                }
            } 
            swap(nums[idx-1],nums[prev]);
            sort(nums.begin()+idx, nums.end());
        }
        
    }
};