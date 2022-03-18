class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        vector<int> v;
        for(int k = 0; k < s.length(); k++){
            int i = startPos[1];
            int j = startPos[0];
            int ans = 0;
            for(int p = k; p < s.length(); p++){
               if(s[p] == 'U'){
                    j--;
                }else if(s[p] == 'R'){
                    i++;
                }else if(s[p] == 'L'){
                    i--;
                }else if(s[p] == 'D'){
                    j++;
                }

                if((i < n && i >= 0) && (j < n && j >= 0)){
                    ans++;
                }else{
                    break;
                } 
            }
            v.push_back(ans);
        }
        return v;
    }
};