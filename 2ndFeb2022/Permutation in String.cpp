// Permutation in String

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Prob Link: https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool areSame(int arr1[], int arr2[]){
        for(int i = 0; i < 256; i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int arr1[256] = {0};
        int arr2[256] = {0};
        
        if(s1.length() > s2.length()){
            return false;
        }
        
        for(int i = 0; i < s1.length(); i++){
            arr1[s1[i]]++;
            arr2[s2[i]]++;
        }
        
        for(int i = s1.length(); i < s2.length(); i++){
            if(areSame(arr1, arr2)){
                return true;
            }
            arr2[s2[i]]++;
            arr2[s2[i-s1.length()]]--;
        }
        if(areSame(arr1, arr2)){
            return true;
        }
        return false;
    }
};