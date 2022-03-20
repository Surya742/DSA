class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> countA(7, 0);
        vector<int> countB(7, 0);
        vector<int> same(7, 0);
        int n = tops.size();
        
        for(int i = 0; i < n; i++){
            countB[bottoms[i]]++;
            countA[tops[i]]++;
            if(tops[i] == bottoms[i]){
                same[tops[i]]++;
            }
        }
        
        for(int i = 0; i < 7; i++){
            if(countA[i]+countB[i]-same[i] == n){
                return n-max(countA[i],countB[i]);
            }
        }
        return -1;
    }
};