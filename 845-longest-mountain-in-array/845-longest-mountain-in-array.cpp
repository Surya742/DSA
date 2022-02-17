class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        for(int i=1; i<arr.size()-1;){
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){ // it is a peak
                int count=1;
                int j=i;
                while(j > 0 and arr[j] > arr[j-1]){
                    count++;
                    j--;
                }
                while(i < arr.size()-1 and arr[i] > arr[i+1]){
                    count++;
                    i++;
                }
                ans = max(ans, count);
            }
            else i++;
        }
        return ans;
    }
};