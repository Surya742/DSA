class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            int x = i;
            vector<int> v;
            while(x > 0){
                int y = x%10;
                x /= 10;
                v.push_back(y);
            }
            bool possible = true;
            for(int k = 0; k < v.size(); k++){
                if(v[k] == 0){
                    possible = false;
                    break;
                }
                if(i%v[k] != 0){
                    possible = false;
                    break;
                }
            }
            if(possible) ans.push_back(i);
        }
        return ans;
    }
};