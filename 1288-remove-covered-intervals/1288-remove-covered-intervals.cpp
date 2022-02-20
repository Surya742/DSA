class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size()-1; i++){
            if((nums[i][0]<=nums[i+1][0] && nums[i][1]>=nums[i+1][1])){
                nums.erase(nums.begin()+i+1);
                --i;
            }
            else if((nums[i][0]>=nums[i+1][0] && nums[i][1]<=nums[i+1][1])){
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        return nums.size();
    }
};