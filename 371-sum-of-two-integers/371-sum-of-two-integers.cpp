class Solution {
public:
    int getSum(int a, int b) {
        if(a > b) swap(a,b);
        while(a != 0){
            if(a < 0){
                a++;
                b--;
            }else{
                a--;
                b++;
            }
        }
        return b;
    }
};