class Solution {
private:
    int parent[10000];
    int rank[10000];
    
    void makeSet(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    int doUnion(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v) return 1;
        if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[v] < rank[u]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u]++;
        }
        return 0;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        makeSet(edges.size());
        for(int i = 0; i < edges.size(); i++){
            int x = doUnion(edges[i][0], edges[i][1]);
            if(x){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                break;
            }
        }
        return ans;
    }
};