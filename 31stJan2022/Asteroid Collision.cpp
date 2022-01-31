// 735. Asteroid Collision

// We are given an array asteroids of integers representing asteroids in a row.

// For each asteroid, the absolute value represents its size, and the sign represents 
// its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the 
// smaller one will explode. If both are the same size, both will explode. Two asteroids 
// moving in the same direction will never meet.

// Prob Link: https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        
        stack<int> st;
        
        
        for(auto i:a){
            if(i>0){
                st.push(i);
            }else{
                while(st.size()>0 && st.top()>0 &&st.top()<-i){
                    st.pop();
                }
                if(st.size()>0 && st.top() == -i){
                    st.pop();
                }else if(st.size()>0 && st.top()>-i){
                }else{
                    st.push(i);
                }
            }
        }
        
        
        vector<int> ans;
        while(st.empty() != true){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};