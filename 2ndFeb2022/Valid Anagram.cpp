// Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word 
// or phrase, typically using all the original letters exactly once.

// Prob Link: https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[256] = {0};
        
        if(s.length() != t.length()){
            return false;
        }
        
        for(int i = 0 ; i < s.length(); i++){
            arr[s[i]]++;
            arr[t[i]]--;
        }
        
        for(int i = 0; i < 256; i++){
            if(arr[i] != 0){
                return false;
            }
        }
        return true;
    }
};