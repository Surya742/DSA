class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        int ans = 0;
        for(auto it: words1){
            mp1[it]++;
        }
        for(auto it: words2){
            mp2[it]++;
        }
        for(int i = 0; i < words1.size(); i++){
            if(mp1[words1[i]] == 1){
                if(mp2[words1[i]]){
                    if(mp2[words1[i]] == 1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};