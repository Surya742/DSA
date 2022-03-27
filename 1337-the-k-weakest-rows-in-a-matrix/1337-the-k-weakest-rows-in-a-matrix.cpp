class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int  i = mat.size() - 1; i >= 0; i--){
            int cnt = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1){
                    cnt++;
                }else{
                    break;
                }
            }
            pq.push({cnt,i});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            int x = pq.top().second;
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};