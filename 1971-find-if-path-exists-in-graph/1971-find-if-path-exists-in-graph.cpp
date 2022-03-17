class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> bfsArr;
        vector<int> vis(n+1, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfsArr.push_back(node);
                    for(auto it: adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
            
            bool isSrc = false;
            bool isDes = false;
            for(auto it: bfsArr){
                if(it == source){
                    isSrc = true;
                }
                if(it == destination){
                    isDes = true;
                }
            }
            bfsArr.clear();
            if(isSrc && isDes){
                return true;
            }else if((isSrc && !isDes) || (!isSrc && isDes)){
                return false;
            }
        }
        return true;
    }
};