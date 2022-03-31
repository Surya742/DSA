class Solution {
private:
    bool isValid(vector<int> &nums, int k, int mx){
        int sum = 0;
        int student = 1;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            if(sum > mx){
                student++;
                sum = nums[i];
            }
        }
        if(student > k){
            return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int start = *max_element(nums.begin(), nums.end());
        int end = 0;
        for(auto it: nums){
            end += it;
        }
        int res = -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isValid(nums,m,mid)){
                res = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return res;
    }
};