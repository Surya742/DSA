// Ugly Number

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return true if n is an ugly number.

// Prob Link: https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int num) {
      
        for (int i=2; i<6 && num; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;  
        }
};