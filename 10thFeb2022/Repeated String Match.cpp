// Repeated String Match

// Given two strings a and b, return the minimum number of times you should repeat string a so that string
//  b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

// Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

// Prob link: https://leetcode.com/problems/repeated-string-match/

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string as = a;
        for (int rep = 1; rep <= b.length() / a.length() + 2; rep++, as += a)
            if (as.find(b) != string::npos) return rep;
        return -1;
    }
};