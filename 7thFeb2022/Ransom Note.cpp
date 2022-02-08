// Ransom Note

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Prob Link:https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto it: ransomNote){
            mp[it]++;
        }
        for(auto it: magazine){
            if(mp[it]){
                mp[it]--;
            }
        }
        for(auto it: mp){
            if(it.second > 0){
                return false;
            }
        }
        return true;
    }
};