class Solution {
public:
    
    
    int find(vector<int>& nums){
     int size = nums.size();
        int l = 0;
        int h = size-1;
        int res = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            int prev = (size+mid-1)%size;
            int next = (mid+1)%size;
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]){
                return mid;
             }else if(nums[mid] <= nums[size-1]){
                
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
}

bool search(vector<int>& nums, int target) {
        set<int> s;
        for(auto it: nums){
            s.insert(it);
        }
        vector<int> newNums;
        for(auto it: s){
            newNums.push_back(it);
        }
        int size = newNums.size();

        int l = 0;
        int h = size-1;
        int res = find(newNums);
        // cout<<"res: "<<res<<endl;
         l = 0;
        h = res-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(newNums[mid] == target){
                return true;
            }else if(newNums[mid] < target){
                l = mid+1;
            }else {
                h = mid-1;
            }
        }
        
        
         l = res;
        h = size-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(newNums[mid] == target){
                return true;
            }else if(newNums[mid] < target){
                l = mid+1;
            }else {
                h = mid-1;
            }
        }
        
        return false;
        
    }

};