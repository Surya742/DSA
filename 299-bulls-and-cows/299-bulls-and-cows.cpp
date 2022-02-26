class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        for(int i= 0; i < secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
        }
        
        unordered_map<char,int> mp;
        for(auto it: secret){
            mp[it]++;
        }
        
        int sum1 = 0;
        for(auto it: mp){
            sum1 += it.second;
        }
        
        for(auto it: guess){
            if(mp.count(it)){
                if(mp[it] > 0){
                    mp[it]--;
                }
            }
        }
        int sum2 = 0;
        for(auto it: mp){
            sum2 += it.second;
        }
        
        int cow = sum1-sum2-bulls;
        string ans = to_string(bulls) + "A" + to_string(cow) + "B";
        return ans;
    }
};