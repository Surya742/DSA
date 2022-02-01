// 2126. Destroying Asteroids
// You are given an integer mass, which represents the original mass of a planet. 
// You are further given an integer array asteroids, where asteroids[i] is the mass of the ith asteroid.

// You can arrange for the planet to collide with the asteroids in any arbitrary order. 
// If the mass of the planet is greater than or equal to the mass of the asteroid, the asteroid 
// is destroyed and the planet gains the mass of the asteroid. Otherwise, the planet is destroyed.

// Return true if all asteroids can be destroyed. Otherwise, return false.

// Prob Link: https://leetcode.com/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        sort(arr.begin(), arr.end());
     long long sum = mass;
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] > sum) return false;
            sum += arr[i];
        }
        return true;   
    }
};