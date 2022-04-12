class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (grid.empty() || k == 0) {
            return grid;
        }
        
        const int width = grid[0].size();
        const int height = grid.size();
        const int maxSize = width * height;
        
        std::vector<std::vector<int>> result;
        for (int i = 0; i < height; ++i) {
            std::vector<int> row;
            row.resize(width);
            
            result.emplace_back(std::move(row));
        }
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int index = i * width + j;
                int updatedIndex = (index + k) % maxSize;
                
                int newRow = updatedIndex / width;
                int newCol = updatedIndex % width;
                
                result[newRow][newCol] = grid[i][j];
            }
        }
        
        return result;
    }
};