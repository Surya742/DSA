class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> v(edges.size()+2);
        for(int i = 0; i < edges.size(); i++){
            v[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> vv(edges.size()+2, 0);
        for(int i = 1; i < v.size(); i++){
            for(auto it: v[i]){
                vv[it]++;
            }
        }
        int mx = INT_MIN;
        int ans = -1;
        for(int i = 1; i < vv.size(); i++){
            if(vv[i] > mx){
                mx = vv[i];
                ans = i;
            }
        }
        return ans;
    }
};