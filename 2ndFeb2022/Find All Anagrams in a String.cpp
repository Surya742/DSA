// Find All Anagrams in a String
// Given two strings s and p, return an array of all the start indices of p's 
// anagrams in s. You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different 
// word or phrase, typically using all the original letters exactly once.

// Prob Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    bool areEqual(int arr1[], int arr2[]) {
        // Linearly compare elements
        for (int i = 0; i < 256; i++)
            if (arr1[i] != arr2[i])
                return false;

        // If all elements were same.
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(s.length() < p.length()) return v;
        int countTxt[256] = {0};
        int countPat[256] = {0};
        
        for(int i = 0; i < p.length(); i++){
            countTxt[s[i]]++;
            countPat[p[i]]++;
        }
        
        for(int i = p.length(); i < s.length(); i++){
            if(areEqual(countTxt, countPat)){
                v.push_back(i-p.length());
            }
            countTxt[s[i]]++;
            countTxt[s[i-p.length()]]--;
        }
        if(areEqual(countTxt, countPat)){
            v.push_back(s.length()-p.length());
        }
        return v;
    }
};