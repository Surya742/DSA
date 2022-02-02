// Group Anagrams
// Given an array of strings strs, group the anagrams together. 
// You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters 
// of a different word or phrase, typically using all the original letters exactly once.

// Prob Link: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string>> mp;
        for(auto i:str)
        {
            string temp=i;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> res;
        for(auto j:mp)
            res.push_back(j.second);
        return res;
    }
};