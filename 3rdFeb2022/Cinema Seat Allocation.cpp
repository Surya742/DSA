// Cinema Seat Allocation

// A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, 
// labelled from 1 to 10 as shown in the figure above.

// Given the array reservedSeats containing the numbers of seats already reserved, for 
// example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

// Return the maximum number of four-person groups you can assign on the cinema seats. 
// A four-person group occupies four adjacent seats in one single row. Seats across an 
// aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an 
// exceptional case on which an aisle split a four-person group, in that case, the aisle 
// split a four-person group in the middle, which means to have two people on each side.

//Prob Link: https://leetcode.com/problems/cinema-seat-allocation/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int,unordered_map<int,int>> mp;
        int ans = n*2;
        for(auto it: rs){
            if(it[1] != 1 && it[1] != 10){
                mp[it[0]][it[1]]++;
            }
        }
                   
        for(auto &it: mp){
            auto &row = it.second;
            if(row.empty()){
                continue;
            }
            
            if( ((row[6] || row[7]) && (row[2] || row[3] || row[4] || row[5])) || ((row[4] || row[5]) && (row[6] || row[7] || row[8] || row[9])) ){
                ans -= 2;
            }else{
                ans -= 1;
            }
        }
        return ans;
    }
};
