class Solution {
public:
    int minMoves(int target, int maxDoubles) {
       vector<int> halfs;
        int ref = target;
        while(maxDoubles && ref){
            ref = ref/2;
            maxDoubles--;
            if(ref>0)
                halfs.push_back(ref);
        }
        int sum = 1;
        int moves = 0;
        for(int i = halfs.size()-1; i >= 0; i--){
            if(halfs[i]==sum){
                moves++;
                sum *= 2;
            }else{
                moves += halfs[i]-sum;
                sum = halfs[i];
                i++;
            }
        }
        moves += target-sum;
        return moves;
    }
};