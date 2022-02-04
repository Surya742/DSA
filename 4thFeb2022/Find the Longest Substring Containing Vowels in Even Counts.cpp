// Find the Longest Substring Containing Vowels in Even Counts
// Given the string s, return the size of the longest substring containing each vowel an even number 
// of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

// Problem Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution {
public:
    int findTheLongestSubstring(string ss) {
        unordered_map<string,int> mp;
        int ans = 0;
        int idx = 0;
        int a = 0;
        int e = 0;
        int i = 0;
        int o = 0;
        int u = 0;
        string s = "-----";
        mp[s] = -1;
        
        for(char it: ss){
            if(it == 'a') a = !a;
            if(it == 'e') e = !e;
            if(it == 'i') i = !i;
            if(it == 'o') o = !o;
            if(it == 'u') u = !u;
            
            if(a) s[0] = 'a'; else s[0] = '-';
            if(e) s[1] = 'e'; else s[1] = '-';
            if(i) s[2] = 'i'; else s[2] = '-';
            if(o) s[3] = 'o'; else s[3] = '-';
            if(u) s[4] = 'u'; else s[4] = '-';
            
            if(mp.find(s) != mp.end()){
                ans = max(ans, idx-mp[s]);
            }else{
                mp[s] = idx;
            }
            idx++;
        }
        return ans;
    }
};