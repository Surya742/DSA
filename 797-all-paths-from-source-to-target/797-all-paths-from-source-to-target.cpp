class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dest = graph.size()-1;
        
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(src,dest,graph,ans,temp);
        return ans;
    }
    
    void dfs(int src, int dest, vector<vector<int>>& graph, vector<vector<int>> &ans, vector<int> temp){
        temp.push_back(src);
        
        if(src == dest){
            ans.push_back(temp);
            return;
        }
        
        for(auto it: graph[src]){
            dfs(it,dest,graph,ans,temp);
        }
    }
};