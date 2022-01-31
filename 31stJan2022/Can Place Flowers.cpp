// 605. Can Place Flowers
// You have a long flowerbed in which some of the plots are planted, 
// and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty 
// and 1 means not empty, and an integer n, return if n new flowers can be planted 
// in the flowerbed without violating the no-adjacent-flowers rule.

//Prob Link: https://leetcode.com/problems/can-place-flowers/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if( n == 0) return true;
        for(int i = 0; i < f.size(); i++){
            if(f[i] == 0 && (i == 0 || f[i-1] == 0) && (i == f.size()-1 || f[i+1] == 0)){
                --n;
                if(n == 0) return true;
                f[i] = 1;
            }
        }
        return false;
    }
};