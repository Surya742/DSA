class Solution {
public:
    vector<vector<int>> generate(int nums) {
        vector<vector<int>> ans;
        if(nums == 1){
            vector<int> v;
            v.push_back(1);
            ans.push_back(v);
            return ans;
        }
        
        if(nums == 2){
            vector<int> v;
            v.push_back(1);
            ans.push_back(v);
            v.push_back(1);
            ans.push_back(v);
            return ans;
        }
        
            vector<int> v;
            v.push_back(1);
            ans.push_back(v);
            v.push_back(1);
            ans.push_back(v);
        
        for(int i = 2; i < nums; i++){
            vector<int> vv;
            vv.push_back(1);
            for(int j = 1; j < ans[ans.size()-1].size(); j++){
                vv.push_back(ans[ans.size()-1][j-1]+ans[ans.size()-1][j]);
            }
            vv.push_back(1);
            ans.push_back(vv);
        }
        return ans;
    }
};