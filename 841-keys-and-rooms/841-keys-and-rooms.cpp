class Solution {
private:
    void bfs(vector<vector<int>> adj, vector<int> &vis, int src){
        vis[src] = 1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(!vis[it]){
                    cout<<it<<" ";
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n+1, 0);
        for(int i = 0; i < rooms.size(); i++){
            if(!vis[i]){
                if(i != 0) return false;
                bfs(rooms, vis, i);
            }
        }
        return true;
    }
};