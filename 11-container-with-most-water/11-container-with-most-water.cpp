class Solution {
public:
    int maxArea(vector<int>& height) {
        int lhs = 0, rhs = height.size() - 1;
        int max_area = 0;
        while (lhs < rhs) {
            max_area = std::max(std::min(height[lhs], height[rhs]) * (rhs - lhs), max_area);
            if (height[lhs] < height[rhs]) { 
                lhs++; 
            } else if (height[lhs] > height[rhs]) { 
                rhs--; 
            } else { 
                lhs++; rhs--; 
            }
        }
        return max_area;
    }
};