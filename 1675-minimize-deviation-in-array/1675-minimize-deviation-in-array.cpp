class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> mh;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(auto it: nums){
            if(it%2 != 0){
                it = it*2;
            }
            mn = min(mn,it);
            mh.push(it);
        }
        int diff = mh.top()-mn;
        
        while(mh.top()%2 == 0){
            int maxx = mh.top();
            mh.pop();
            diff = min(diff, maxx-mn);
            maxx /= 2;
            mn = min(mn,maxx);
            mh.push(maxx);
        }
        diff = min(diff, mh.top()-mn);
        return diff;
    }
};