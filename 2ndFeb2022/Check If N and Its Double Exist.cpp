// Check If N and Its Double Exist
// Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

// More formally check if there exists two indices i and j such that :

// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]

// Prob Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        vector<int> v;
        for(auto it: arr){
            v.push_back(it*2);
        }
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < arr.size(); j++){
                if(arr[j] == v[i] && i != j){
                    return true;
                }
            }
        }
        return false;
    }
};