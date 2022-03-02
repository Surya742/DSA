class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
         int m = n;
        
         for(int i=0;i<n;i++){
             for(int j=0;j<i;j++){
                 //transpose
                 swap(matrix[i][j],matrix[j][i]);
             }
         }
        // loop for every row and reverse it
         for(int i=0;i<n;i++){
             reverse(matrix[i].begin(),matrix[i].end());
         }
    }
};