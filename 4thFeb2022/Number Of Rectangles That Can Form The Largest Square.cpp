// Number Of Rectangles That Can Form The Largest Square

// You are given an array rectangles where rectangles[i] = [li, wi] represents the ith rectangle of length li and width wi.

// You can cut the ith rectangle to form a square with a side length of k if both k <= li and k <= wi. 
// For example, if you have a rectangle [4,6], you can cut it to get a square with a side length of at most 4.

// Let maxLen be the side length of the largest square you can obtain from any of the given rectangles.

// Return the number of rectangles that can make a square with a side length of maxLen.

// Problem Link: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        vector<int> v;
        int maxLen = 0;
        for(int i = 0; i < r.size(); i++){
            v.push_back(min(r[i][0], r[i][1]));
            maxLen = max(maxLen, min(r[i][0], r[i][1]));
        }
        int ans = 0;
        for(auto it: v){
            if(it == maxLen){
                ans++;
            }
        }
        return ans;
    }
};
