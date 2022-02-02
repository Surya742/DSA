// Queens That Can Attack the King
// On an 8x8 chessboard, there can be multiple Black Queens and one White King.

// Given an array of integer coordinates queens that represents the positions
//  of the Black Queens, and a pair of coordinates king that represent the position 
//  of the White King, return the coordinates of all the queens (in any order) that can attack the King.

// Prob Link: https://leetcode.com/problems/queens-that-can-attack-the-king/

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& q, vector<int>& k) {
        vector<vector<int>> ans;
        vector<int> v;
        
        //vertical
        for(int i = 0; i < q.size(); i++){
            if(q[i][1] == k[1]){
                v.push_back(q[i][0]);
            }
        }
        
        int upperMin = INT_MAX;
        int lowerMin = INT_MAX;
        int upperSum = INT_MAX;
        int lowerSum = INT_MAX;
        
        for(int i = 0; i < v.size(); i++){
            if(v[i] < k[0]){
                if(k[0] - v[i] < upperSum){
                    upperSum = k[0]-v[i];
                    upperMin = v[i];
                }
            }else {
                if(v[i]-k[0] < lowerSum){
                    lowerSum = v[i]-k[0];
                    lowerMin = v[i];
                }
            }
        }
        
        if(lowerMin != INT_MAX){
            vector<int> t;
            t.push_back(lowerMin);
            t.push_back(k[1]);
            ans.push_back(t);
        }
        if(upperMin != INT_MAX){
            vector<int> t;
            t.push_back(upperMin);
            t.push_back(k[1]);
            ans.push_back(t);
        }
        
        //Horizontal
        v.clear();
        for(int i = 0; i < q.size(); i++){
            if(q[i][0] == k[0]){
                v.push_back(q[i][1]);
            }
        }
        
        int leftMin = INT_MAX;
        int rightMin = INT_MAX;
        int leftSum = INT_MAX;
        int rightSum = INT_MAX;
        
        for(int i = 0; i < v.size(); i++){
            if(v[i] < k[1]){
                if(k[1] - v[i] < leftSum){
                    leftSum = k[1]-v[i];
                    leftMin = v[i];
                }
            }else {
                if(v[i]-k[1] < rightSum){
                    rightSum = v[i]-k[1];
                    rightMin = v[i];
                }
            }
        }
        
        if(rightMin != INT_MAX){
            vector<int> t;
            t.push_back(k[0]);
            t.push_back(rightMin);
            ans.push_back(t);
        }
        if(leftMin != INT_MAX){
            vector<int> t;
            t.push_back(k[0]);
            t.push_back(leftMin);
            ans.push_back(t);
        }
        
        //Diagnal
        vector<vector<int>> v1;
        vector<vector<int>> v2;
        vector<vector<int>> v3;
        vector<vector<int>> v4;
        
        for(auto ele: q){
            if(abs(k[0]-ele[0]) == abs(k[1]-ele[1])){
                if(k[0]-ele[0] > 0 && k[1]-ele[1] > 0){
                    vector<int> t;
                    t.push_back(ele[0]);
                    t.push_back(ele[1]);
                    v1.push_back(t);
                }else if(k[0]-ele[0] > 0 && k[1]-ele[1] < 0){
                    vector<int> t;
                    t.push_back(ele[0]);
                    t.push_back(ele[1]);
                    v2.push_back(t);
                }else if(k[0]-ele[0] < 0 && k[1]-ele[1] < 0){
                    vector<int> t;
                    t.push_back(ele[0]);
                    t.push_back(ele[1]);
                    v3.push_back(t);
                }else{
                    vector<int> t;
                    t.push_back(ele[0]);
                    t.push_back(ele[1]);
                    v4.push_back(t);
                }
            }
        }
        
        vector<int> v1Min;
        vector<int> v2Min;
        vector<int> v3Min;
        vector<int> v4Min;
        
        int v1Sum = INT_MAX;
        int v2Sum = INT_MAX;
        int v3Sum = INT_MAX;
        int v4Sum = INT_MAX;
        
        for(auto it: v1){
            if(k[0]-it[0] < v1Sum){
                v1Sum = k[0]-it[0];
                v1Min.clear();
                v1Min.push_back(it[0]);
                v1Min.push_back(it[1]);
            }
        }
        
        for(auto it: v2){
            if(k[0]-it[0] < v2Sum){
                v2Sum = k[0]-it[0];
                v2Min.clear();
                v2Min.push_back(it[0]);
                v2Min.push_back(it[1]);
            }
        }
        
        for(auto it: v3){
            if(it[0]-k[0] < v3Sum){
                v3Sum = it[0]-k[0];
                v3Min.clear();
                v3Min.push_back(it[0]);
                v3Min.push_back(it[1]);
            }
        }
        
        for(auto it: v4){
            if(it[0]-k[0] < v4Sum){
                v4Sum = it[0]-k[0];
                v4Min.clear();
                v4Min.push_back(it[0]);
                v4Min.push_back(it[1]);
            }
        }
        
        if(v1Min.size() == 2){
            ans.push_back(v1Min);
        }
        
        if(v2Min.size() == 2){
            ans.push_back(v2Min);
        }
        
        if(v3Min.size() == 2){
            ans.push_back(v3Min);
        }
        
        if(v4Min.size() == 2){
            ans.push_back(v4Min);
        }
        
        v.clear();
        v1.clear();
        v2.clear();
        v3.clear();
        v4.clear();
        
        return ans;
        
    }
};