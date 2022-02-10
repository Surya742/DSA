// Implement strStr()

// Prob Link: https://leetcode.com/problems/implement-strstr/

// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

class Solution {
public:
    vector<int> prefixSum(string s){
        int n = s.length();
        vector<int> pi(n,0);
        for(int i = 1; i < n; i++){
            int j = pi[i-1];
            while(j>0 && s[i]!=s[j]){
                j=pi[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;
        vector<int> res = prefixSum(needle);
        
        int pos = -1;
        int i(0),j(0);
        while(i < haystack.length()){
            if(haystack[i] == needle[j]){
                j++;
                i++;
            }else{
                if(j!=0){
                    j=res[j-1];
                }else{
                    i++;
                }
            }
            if(j == needle.length()){
                pos = i - needle.length();
                break;
            }
        }
        return pos;
    }
};