// 495. Teemo Attacking

// Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, 
// Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is 
// poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends,
// the timer for it is reset, and the poison effect will end duration seconds after the new attack.

// You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks 
// Ashe at second timeSeries[i], and an integer duration.

// Return the total number of seconds that Ashe is poisoned.

// Problem Link: https://leetcode.com/problems/teemo-attacking/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        for(int i = 0; i < timeSeries.size(); i++){
            if(i == 0){
                ans += duration;
            }else {
                if(timeSeries[i-1]+duration >= timeSeries[i]){
                    ans += timeSeries[i]-timeSeries[i-1];
                }else {
                    ans += duration;
                }
            }
        }
        return ans;
    }
};