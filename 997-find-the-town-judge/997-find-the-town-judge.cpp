class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> v(n+1);
        for(int i = 0; i < trust.size(); i++){
            v[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i = 1; i < v.size(); i++){
            if(v[i].size() == 0){
                for(int j = 1; j < v.size(); j++){
                    if(i != j){
                        bool found = false;
                        for(auto it: v[j]){
                            if(it == i){
                                found = true;
                            }
                        }
                        if(!found) return -1;
                    }
                }
                return i;
            }
        }
        return -1;
    }
};