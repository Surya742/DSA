class Solution {
public:
    unordered_set<string> vis;
    
    void dfs(unordered_map<string, vector<pair<string, double>>>& graph, string u, string dest, double cost_till_here, double &ans)
    {
        if(u == dest)
        {
            ans = cost_till_here;
            
            return;
        }
        
        vis.insert(u);
        
        for(auto x : graph[u])
        {
            string v = x.first;
                
            double weight = x.second;
                
            if(vis.count(v) == 0)
            {
                dfs(graph, v, dest, cost_till_here * weight, ans);
            }
        }
    }
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> graph;
        
        for(int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            
            string v = equations[i][1];
            
            double val = values[i];
            
            graph[u].push_back({v, val});
            
            graph[v].push_back({u, 1.0 / val});
        }
        
        vector<double> res;
        
        for(int i = 0; i < queries.size(); i++)
        {
            vis.clear();
            
            string u = queries[i][0];
            
            string v = queries[i][1];
            
            if(graph.count(u) == 0 || graph.count(v) == 0)
            {
                res.push_back(-1);
            }
            else
            {
                double ans = -1;
                
                dfs(graph, u, v, 1, ans);
                
                res.push_back(ans);
            }
        }
        
        return res;
    }
};