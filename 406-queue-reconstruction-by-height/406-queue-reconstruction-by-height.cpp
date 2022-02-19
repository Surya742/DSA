class Solution {
public:
     static bool myComp(vector<int>&a, vector<int>&b)
    {
        if(a[0] != b[0])
        {
            return a[0] < b[0];
        }
        else
        {
            return a[1] > b[1]; 
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), myComp);
       
        for(int i = people.size() - 1; i >= 0; i--)
        {
             ans.insert(ans.begin() + people[i][1], {people[i][0], people[i][1]});          
        }
        return ans;
    }
};