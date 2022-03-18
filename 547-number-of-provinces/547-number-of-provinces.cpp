class Solution {
private:
    void bfsTraversal(int src, vector<int> &vis, vector<int> adj[]){
        vis[src] = 1;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int bfs(vector<int> adj[], int n){
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(!vis[i]){
                ans++;
                bfsTraversal(i, vis, adj);
            }
        }
        return ans;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> adj[isConnected.size()+1];
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected[i].size(); j++){
                if(i != j){
                    if(isConnected[i][j]){
                        adj[i+1].push_back(j+1);
                        adj[j+1].push_back(i+1);
                        isConnected[i][j] = 0;
                        isConnected[j][i] = 0;
                    }
                }
            }
        }
        
        int ans = bfs(adj, isConnected.size()+1);
        return ans;
    }
};