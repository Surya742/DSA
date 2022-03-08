class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

    int k=0;
    map<vector<int>,int> m;
    for(int i=0;i<dominoes.size();i++){
        sort(dominoes[i].begin(),dominoes[i].end());
        if(m.find(dominoes[i])!=m.end()){
            k+=m[dominoes[i]];
            m[dominoes[i]]++;
        }
       else{
           m.insert({dominoes[i],1});
       } 
    }
    return k;
}
};