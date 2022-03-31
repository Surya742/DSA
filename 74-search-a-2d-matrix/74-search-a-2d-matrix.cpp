class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size()-1;
        while(i <= matrix.size()-1 && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }else if(target > matrix[i][j]){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};