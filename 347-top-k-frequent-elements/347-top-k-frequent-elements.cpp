class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        vector<int> v;
        for(int i = 0; i < nums.size(); i++)
        {
            um[nums[i]]++;
        }
        
        unordered_map<int,int>::iterator it;
        unordered_map<int,int>::iterator it2;
        
        for(int i = 0; i < k; i++){
            int m = 0;
            for(it = um.begin(); it != um.end(); it++){
                if(it->second > m){
                    m = it->second;
                    it2 = it;
                };
            }
            v.push_back(it2->first);
            it2->second = 0;
        }
        
        return v;
    }
};