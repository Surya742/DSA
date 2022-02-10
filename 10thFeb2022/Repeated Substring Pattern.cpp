// Repeated Substring Pattern

// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

// Prob link: https://leetcode.com/problems/repeated-substring-pattern/

 class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size()-2).find(s) != -1;
    }
};