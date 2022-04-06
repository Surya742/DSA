class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map <int , long> m;
        int mod = 1e9 +7;
        for(int i : arr) m[i]++;
        long result = 0;
        
        for(auto it: m)                                                         // traversing for i
            for(auto it2: m){                                                   // traversing for j
                int i = it.first , j = it2.first , k = target -i - j;
                if(!m.count(k)) continue;
                if(i==j && j==k){
                    result += m[i] * (m[i]-1) * (m[i]-2) / 6;
                }else if(i==j && j!=k){
                    result += m[i] * (m[i]-1)/2 * m[k];
                }else if(i<j && j<k){
                    result += m[i] * m[j] * m[k];
                }
            }
        return result % mod;
    }
};